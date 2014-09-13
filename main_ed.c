#include "bsp.h"
#include "mrfi.h"
#include "nwk_types.h"
#include "nwk_api.h"
#include "bsp_leds.h"
#include "bsp_buttons.h"
#include "helpers.h"
#include "virtual_com_cmds.h"
#include "protocol.h"


int commandToProcess = 0;;
uint8_t rxMsg, txMsg[4];

static linkID_t sLinkID1 = 0;

/* application Rx frame handler. */
static uint8_t sRxCallback(linkID_t);

#define SPIN_ABOUT_A_SECOND  NWK_DELAY(1000)


static void ed_loop()
{
	int retVal = SMPL_NO_ACK;

	int retr = 0;

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
		toggleLED(1);
	}

	/* turn on RX. default is RX off. */
	SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXON, 0);

	while (1)
	{
		if (commandToProcess)
		{
			retr = 5;
			NWK_DELAY(1000);
			while((retVal != SMPL_SUCCESS)||(retr!=0))
			{
				retVal =  SMPL_Send(sLinkID1, txMsg, sizeof(txMsg));
				toggleLED(2);
				NWK_DELAY(1000);

				retr--;
			}

			commandToProcess = 0;

		}
	}
}




/* handle received frames. */
static uint8_t sRxCallback(linkID_t port)
{
  uint8_t len;

  toggleLED(1);

  if (port == sLinkID1)
  {
	  if ((SMPL_SUCCESS == SMPL_Receive(sLinkID1, &rxMsg, &len)) && len)
	  {
		  switch(rxMsg)
		  {
			  case ED_GET_TEMP_IN:
			  {
				  txMsg[0] = 1;
				  txMsg[1] = 2;
				  txMsg[2] = 3;
				  txMsg[3] = 4;
				  break;
			  }
			  case ED_GET_TEMP_OUT:
			  {
				  txMsg[0] = 5;
				  txMsg[1] = 6;
				  txMsg[2] = 7;
				  txMsg[3] = 8;
				  break;
			  }
			  case ED_GET_HUM:
			  {
				  txMsg[0] = 9;
				  txMsg[1] = 10;
				  txMsg[2] = 11;
				  txMsg[3] = 12;
				  break;
			  }
			  case ED_GET_RAIN:
			  {
				  txMsg[0] = 13;
				  txMsg[1] = 14;
				  txMsg[2] = 15;
				  txMsg[3] = 16;
				  break;
			  }
			  case ED_GET_WINDOWS_STATE:
			  {
				  txMsg[0] = 17;
				  txMsg[1] = 18;
				  txMsg[2] = 19;
				  txMsg[3] = 20;
				  break;
			  }
			  default:
			  {
				  txMsg[0] = 0xFF;
				  txMsg[1] = 0xFF;
				  txMsg[2] = 0xFF;
				  txMsg[3] = 0xFF;
				  break;
			  }
		  }
		  commandToProcess = 1;

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
