/********************************************************************************************************
 * @file    tlkapp.c
 *
 * @brief   This is the source file for BTBLE SDK
 *
 * @author  BTBLE GROUP
 * @date    2022
 *
 * @par     Copyright (c) 2022, Telink Semiconductor (Shanghai) Co., Ltd.
 *          All rights reserved.
 *
 *          The information contained herein is confidential property of Telink
 *          Semiconductor (Shanghai) Co., Ltd. and is available under the terms
 *          of Commercial License Agreement between Telink Semiconductor (Shanghai)
 *          Co., Ltd. and the licensee or the terms described here-in. This heading
 *          MUST NOT be removed from this file.
 *
 *          Licensee shall not delete, modify or alter (or permit any third party to delete, modify, or
 *          alter) any information contained herein in whole or in part except as expressly authorized
 *          by Telink semiconductor (shanghai) Co., Ltd. Otherwise, licensee shall be solely responsible
 *          for any claim to the extent arising out of or relating to such deletion(s), modification(s)
 *          or alteration(s).
 *
 *          Licensees are granted free, non-transferable use of the information in this
 *          file under Mutual Non-Disclosure Agreement. NO WARRANTY of ANY KIND is provided.
 *
 *******************************************************************************************************/


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


