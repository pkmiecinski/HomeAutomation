#include "bsp.h"
#include "mrfi.h"
#include "nwk_types.h"
#include "nwk_api.h"
#include "bsp_leds.h"
#include "bsp_buttons.h"
#include "virtual_com_cmds.h"
#include "helpers.h"
#include "string.h"
#include "protocol.h"


static          linkID_t sLinkID2 = 0;
static volatile uint8_t  waitingForResponse = 0;

int sendMessage = 0;
char uartBuff[50];
uint8_t txMsg, rxMsg[4];


/* Rx callback handler */
static uint8_t sRxCallback(linkID_t);


static void ap_loop()
{
  int retVal;

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

   trace("Connected! Waiting for commands\n\r");

   while (1)
   {
	   if (BSP_BUTTON1() || BSP_BUTTON2())
	   {
		   txMsg = ED_GET_TEMP_IN;
		   NWK_DELAY(100);
    	   waitingForResponse = 1;
		   trace("command sent, waiting for response.. \n\r");
	   }

	   if (sendMessage)
	   {
		   retVal =  SMPL_Send(sLinkID2, &txMsg, sizeof txMsg);
		   sendMessage = 0;
	   }
   }

}

/* handle received messages */
static uint8_t sRxCallback(linkID_t port)
{
  uint8_t len;

  if (port == sLinkID2)
  {
    /* yes. go get the frame. we know this call will succeed. */
     if ((SMPL_SUCCESS == SMPL_Receive(sLinkID2, rxMsg, &len)) && len)
     {
       trace("Got the frame -  ");

       itoa(rxMsg[0],uartBuff, 16);
       TXString(uartBuff, 1);
       itoa(rxMsg[1],uartBuff, 16);
       TXString(uartBuff, 1);
       itoa(rxMsg[2],uartBuff, 16);
       TXString(uartBuff, 1);
       itoa(rxMsg[3],uartBuff, 16);
       TXString(uartBuff, 1);

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


/*------------------------------------------------------------------------------
* USCIA interrupt service routine
------------------------------------------------------------------------------*/
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
  char rx = UCA0RXBUF;
  if ( rx == 'I' || rx == 'i' )
  {
	  txMsg = ED_GET_TEMP_IN;
  }
  else if ( rx == 'O' || rx == 'o' )
  {
	  txMsg = ED_GET_TEMP_OUT;
  }
  else if ( rx == 'H' || rx == 'h' )
  {
	  txMsg = ED_GET_HUM;
  }
  else if ( rx == 'R' || rx == 'r' )
  {
	  txMsg = ED_GET_RAIN;
  }
  else if (rx == 'W'|| rx == 'w')
  {
	  txMsg = ED_GET_WINDOWS_STATE;
  }
  else
  {
	  trace("Command not supported!\n\r");
	  return;
  }

  sendMessage = 1;
}
