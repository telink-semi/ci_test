/********************************************************************************************************
 * @file	tlkmain.c
 *
 * @brief	This is the source file for BTBLE SDK
 *
 * @author	BTBLE GROUP
 * @date	2022
 *
 * @par     Copyright (c) 2022, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
#include "tlkapi/tlkapi_stdio.h"
#include "tlkapp.h"
#include "drivers.h"

#include "tlkstk/inner/tlkstk_inner.h"
#include "tlkstk/ble/ble.h"
#if TEST_MODE==BQB
extern void btc_ll_system_tick_isr(void);
extern void btc_core_isr(void);
#endif

/******************************************************************************
 * Function: main
 * Descript: This is main function.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/
int main(void)
{
#if (MCU_CORE_TYPE == MCU_CORE_B91)
	blc_pm_select_internal_32k_crystal();
	config_obj_init();
	rd_usr_definition(1);
    sys_init(g_bqb_setting.power_mode,VBAT_MAX_VALUE_GREATER_THAN_3V6);
#endif
#if (MCU_CORE_TYPE == MCU_CORE_B92)
	config_obj_init();
	rd_usr_definition(1);
	 sys_init(g_bqb_setting.power_mode,VBAT_MAX_VALUE_GREATER_THAN_3V6,GPIO_VOLTAGE_3V3);
	/* adjust cap value */
    analog_write_reg8(0x8a, 0x60); //only used for current chip.
    wd_32k_stop();
#endif
    CCLK_48M_HCLK_48M_PCLK_24M;

    ext_gpio_init(1);
    tlkapp_init();
#if (MCU_CORE_TYPE == MCU_CORE_B91)
	core_enable_interrupt();
#endif

#if (MCU_CORE_TYPE == MCU_CORE_B92 && TEST_MODE==BQB)
	tlksys_interrupt_enable();
#endif

	while(1)
	{
		tlkapp_handler();
	}
    return 0;
} 
#if TEST_MODE==BQB
/******************************************************************************
 * Function: stimer_irq_handler
 * Descript: System timer interrupt handler.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/
_attribute_retention_code_ void stimer_irq_handler(void)
{
    btc_ll_system_tick_isr();
    ble_ll_system_tick_isr();
}

/******************************************************************************
 * Function: rf_irq_handler
 * Descript: Baseband interrupt handler.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/
_attribute_retention_code_ void rf_irq_handler(void)
{
	ble_sdk_rf_irq_handler();
}

#if (TLK_USB_AUD_ENABLE)
extern void tlkusb_audirq_handler(void);
#endif
/******************************************************************************
 * Function: usb_endpoint_irq_handler
 * Descript: Usb endpoint interrupt handler.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/
_attribute_retention_code_ 
void usb_endpoint_irq_handler(void)
{
	#if (TLK_USB_AUD_ENABLE)
	tlkusb_audirq_handler();
	#endif
}


/******************************************************************************
 * Function: zb_bt_irq_handler
 * Descript: Bt Core interrupt handler.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/
_attribute_retention_code_ void zb_bt_irq_handler(void)
{
    btc_core_isr();
}
#endif
