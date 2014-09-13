#include "bsp.h"
#include "mrfi.h"
#include "nwk_types.h"
#include "nwk_api.h"
#include "bsp_leds.h"
#include "bsp_buttons.h"
#include "helpers.h"
#include "virtual_com_cmds.h"


static uint8_t  sTxTid=0, sRxTid=0;
static linkID_t sLinkID1 = 0;

/* application Rx frame handler. */
static uint8_t sRxCallback(linkID_t);

#define SPIN_ABOUT_A_SECOND  NWK_DELAY(1000)


static void ed_loop()
{
  uint8_t  msg[2], delay = 0;

  while (SMPL_SUCCESS != SMPL_Link(&sLinkID1))
  {
    /* blink LEDs until we link successfully */
    toggleLED(1);
    toggleLED(2);
    SPIN_ABOUT_A_SECOND;
  }

  /* we're linked. turn off red LED. received messages will toggle the green LED. */
  if (BSP_LED2_IS_ON())
  {
    toggleLED(2);
  }

  /* turn on RX. default is RX off. */
  SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXON, 0);

  /* put LED to toggle in the message */
  msg[0] = 2;  /* toggle red */
  while (1)
  {
    SPIN_ABOUT_A_SECOND;
    if (delay > 0x00)
    {
      SPIN_ABOUT_A_SECOND;
    }
    if (delay > 0x01)
    {
      SPIN_ABOUT_A_SECOND;
    }
    if (delay > 0x02)
    {
      SPIN_ABOUT_A_SECOND;
    }

    /* delay longer and longer -- then start over */
    delay = (delay+1) & 0x03;
    /* put the sequence ID in the message */
    msg[1] = ++sTxTid;
    SMPL_Send(sLinkID1, msg, sizeof(msg));
  }
}




/* handle received frames. */
static uint8_t sRxCallback(linkID_t port)
{
  uint8_t msg[2], len, tid;

  /* is the callback for the link ID we want to handle? */
  if (port == sLinkID1)
  {
    /* yes. go get the frame. we know this call will succeed. */
     if ((SMPL_SUCCESS == SMPL_Receive(sLinkID1, msg, &len)) && len)
     {
       /* Check the application sequence number to detect
        * late or missing frames... 
        */
       tid = *(msg+1);
       if (tid)
       {
         if (tid > sRxTid)
         {
           /* we're good. toggle LED in the message */
           toggleLED(*msg);
           sRxTid = tid;
         }
       }
       else
       {
         /* the wrap case... */
         if (sRxTid)
         {
           /* we're good. toggle LED in the message */
           toggleLED(*msg);
           sRxTid = tid;
         }
       }
       /* drop frame. we're done with it. */
       return 1;
     }
  }
  /* keep frame for later handling. */
  return 0;
}


void main (void)
{
  BSP_Init();

  SMPL_Init(sRxCallback);

  ed_loop();

  while (1) ;
}
