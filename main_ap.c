#include "bsp.h"
#include "mrfi.h"
#include "nwk_types.h"
#include "nwk_api.h"
#include "bsp_leds.h"
#include "bsp_buttons.h"
#include "virtual_com_cmds.h"
#include "helpers.h"



static          uint8_t  sRxTid = 0;
static          linkID_t sLinkID2 = 0;
static volatile uint8_t  sSemaphore = 0;

/* Rx callback handler */
static uint8_t sRxCallback(linkID_t);


static void ap_loop()
{
  uint8_t     msg[2], tid = 0;

  trace("Listening for connections with ED\n");
  while (1)
  {
    if (SMPL_SUCCESS == SMPL_LinkListen(&sLinkID2))
    {
      break;
    }
    /* Implement fail-to-link policy here. otherwise, listen again. */
  }

   /* turn on LED1 on the peer in response to receiving a frame. */
   *msg = 0x02;

   /* turn on RX. default is RX off. */
   SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXON, 0);

   while (1)
   {
     /* Wait for a frame to be received. The Rx handler, which is running in
      * ISR thread, will post to this semaphore allowing the application to
      * send the reply message in the user thread.
      */
     if (sSemaphore)
     {
       *(msg+1) = ++tid;
       SMPL_Send(sLinkID2, msg, 2);

       /* Reset semaphore. This is not properly protected and there is a race
        * here. In theory we could miss a message. Good enough for a demo, though.
        */
       sSemaphore = 0;
     }
   }
}

/* handle received messages */
static uint8_t sRxCallback(linkID_t port)
{
  uint8_t msg[32], len, tid;

  trace("rxCallback ");
  if (port == sLinkID2)
  {
	trace("Propoer linkID. ");
    /* yes. go get the frame. we know this call will succeed. */
     if ((SMPL_SUCCESS == SMPL_Receive(sLinkID2, msg, &len)) && len)
     {
       trace("Got the frame.\n\r");
       /* Check the application sequence number to detect
        * late or missing frames...
        */
       tid = *(msg+1);
       if (tid)
       {
         if (tid > sRxTid)
         {
           /* we're good. toggle LED */
           trace("OK\n\r");
           toggleLED(*msg);
           sRxTid = tid;
         }
       }
       else
       {
         /* wrap case... */
         if (sRxTid)
         {

             trace("OK, but with retransmission\n\r");
           toggleLED(*msg);
           sRxTid = tid;
         }
       }
       /* Post to the semaphore to let application know so it sends
        * the reply
        */
       sSemaphore = 1;
       /* drop frame. we're done with it. */
       return 1;
     }
  }
  /* keep frame for later handling */
  return 0;
}

void main (void)
{
  BSP_Init();

  /* Initialize serial port */
  COM_Init();

  trace("BSP inited\n");

  SMPL_Init(sRxCallback);
  trace("SMPL inited\n");

  ap_loop();

  trace("E: We should never reach it\n");
  while (1) ;
}

