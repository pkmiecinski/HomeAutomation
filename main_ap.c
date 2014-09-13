#include "bsp.h"
#include "mrfi.h"
#include "nwk_types.h"
#include "nwk_api.h"
#include "bsp_leds.h"
#include "bsp_buttons.h"
#include "virtual_com_cmds.h"
#include "helpers.h"
#include "protocol.h"


static          linkID_t sLinkID2 = 0;
static volatile uint8_t  waitingForResponse = 0;

uint8_t txMsg, rxMsg[4];

/* Rx callback handler */
static uint8_t sRxCallback(linkID_t);


static void ap_loop()
{
  int retVal = SMPL_NO_ACK;

  int retr = 0;

  trace("Listening for connections with ED\n\r");
  while (1)
  {
    if (SMPL_SUCCESS == SMPL_LinkListen(&sLinkID2))
    {
      break;
    }
    /* Implement fail-to-link policy here. otherwise, listen again. */
  }

   /* turn on RX. default is RX off. */
   SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXON, 0);

   while (1)
   {
	   txMsg = ED_GET_TEMP_IN;
	   retr = 1;

	   do
	   {
		   while(retVal != SMPL_SUCCESS)
		   {
			   retVal =  SMPL_Send(sLinkID2, &txMsg, sizeof txMsg);
			   NWK_DELAY(1000);
			   trace(".");
		   }
		   waitingForResponse = 1;

		   trace("command sent, waiting for response.. \n\r");
		   NWK_DELAY(3000);
	   } while(--retr);
	   NWK_DELAY(3000);
	   trace ("couldn't send command, once more\n\r");
   }

}

/* handle received messages */
static uint8_t sRxCallback(linkID_t port)
{
  uint8_t len;

  trace("rxCallback ");
  if (port == sLinkID2)
  {
	trace("Propoer linkID. ");
    /* yes. go get the frame. we know this call will succeed. */
     if ((SMPL_SUCCESS == SMPL_Receive(sLinkID2, rxMsg, &len)) && len)
     {
       trace("Got the frame. ");

       if ( rxMsg[0]==4 )
    	   trace("good message in payload\n\r");

       TXString(rxMsg,4);
       trace("\n\r");
       waitingForResponse = 0;
       return 1;
     }
  }

  return 0;
}

void main (void)
{
  BSP_Init();

  /* Initialize serial port */
  COM_Init();

  trace("BSP inited\n\r");

  SMPL_Init(sRxCallback);
  trace("SMPL inited\n\r");

  ap_loop();

  trace("E: We should never reach it\n\r");
  while (1) ;
}

