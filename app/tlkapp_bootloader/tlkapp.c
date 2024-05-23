#include "tlkapi/tlkapi_stdio.h"
#include "tlkapp_config.h"
#include "tlkapp_irq.h"
#include "tlkapp.h"
#include "tlkapp_dfu.h"
#include "drivers.h"






/******************************************************************************
 * Function: tlkapp_init
 * Descript: user initialization when MCU power on or wake_up from deepSleep mode.
 * Params: None.
 * Return: TLK_ENONE is success.
 * Others: None.
*******************************************************************************/  
int tlkapp_init(void)
{
	
	return TLK_ENONE;
}


/******************************************************************************
 * Function: tlkapp_handler
 * Descript: BTBLE SDK main loop.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/
volatile uint32 AAAA_trace01 = 0;
volatile uint32 AAAA_trace02 = 0;
volatile uint32 AAAA_trace03 = 0;
volatile uint32 AAAA_trace04 = 0;

void tlkapp_handler(void)
{
	AAAA_trace01 ++;
	AAAA_trace03 ++;

	if(AAAA_trace02 == 1){
		tlkapp_dfu_load();
		AAAA_trace02 = 0;
//		TLKAPP_JUMP_TO_APP();
	}

	if(AAAA_trace04 == 1){
		AAAA_trace04 = 0;
		TLKAPP_JUMP_TO_APP();
	}
	
}


