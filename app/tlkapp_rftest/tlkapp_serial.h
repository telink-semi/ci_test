/********************************************************************************************************
 * @file	tlkapp_serial.h
 *
 * @brief	This is the header file for BTBLE SDK
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
#ifndef TLKAPP_SERIAL_H
#define TLKAPP_SERIAL_H

#if TLK_DEV_SERIAL_ENABLE
#define TLKAPP_SERIAL_PORT            UART1
#define TLKAPP_SERIAL_TX_PIN          GPIO_PD6
#define TLKAPP_SERIAL_RX_PIN          GPIO_PD7
#define TLKAPP_SERIAL_BAUDRATE        115200//1500000//921600//115200

#define TLKAPP_SERIAL_TX_DMA          DMA4
#define TLKAPP_SERIAL_RX_DMA          DMA5
#define TLKAPP_SERIAL_RBUFF_NUMB      16
#define TLKAPP_SERIAL_RBUFF_SIZE      2048
#define TLKAPP_SERIAL_SBUFF_NUMB      16
#define TLKAPP_SERIAL_SBUFF_SIZE      1024

/******************************************************************************
 * Function: tlkapp_serial_init
 * Descript: Register the usb debug callback.
 * Params: None.
 * Return: TLK_NONE is success.
 * Others: None.
*******************************************************************************/
int tlkapp_serial_init(void);

void tlkapp_serial_handler(void);

#endif

#endif //TLKAPP_SERIAL_H

