/********************************************************************************************************
 * @file	tlkapp.h
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
#ifndef TLKAPP_H
#define TLKAPP_H



#define TLKAPP_DBG_FLAG         ((TLK_MAJOR_DBGID_APP << 24) | (TLK_MINOR_DBGID_APP << 16) | TLK_DEBUG_DBG_FLAG_ALL)
#define TLKAPP_DBG_SIGN         "[APP]"

#if(TLKHW_TYPE == TLKHW_TYPE_C1T213A83_V5_1)
#define TLKAPP_WAKEUP_PIN       GPIO_PA2
#elif(TLKHW_TYPE == TLKHW_TYPE_C1T213A20_V1_3)
#define TLKAPP_WAKEUP_PIN       GPIO_PC3
#elif(TLKHW_TYPE == TLKHW_TYPE_C1T266A83_V1_2)
#define TLKAPP_WAKEUP_PIN       GPIO_PE7
#elif(TLKHW_TYPE == TLKHW_TYPE_C1T266A20_V1_3)
#define TLKAPP_WAKEUP_PIN       GPIO_PE7
#elif (TLKHW_TYPE == TLKHW_TYPE_C1T294A83_V1_0)
#define TLKAPP_WAKEUP_PIN       GPIO_PE7
#else
#define TLKAPP_WAKEUP_PIN       0
#endif




/******************************************************************************
 * Function: tlkapp_init
 * Descript: user initialization when MCU power on or wake_up from deepSleep mode.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/ 
int tlkapp_init(void);

/******************************************************************************
 * Function: tlkapp_deepInit
 * Descript: user initialization when MCU wake_up from deepSleep_retention mode.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/ 
void tlkapp_deepInit(void);

/******************************************************************************
 * Function: tlkapp_handler
 * Descript: BTBLE SDK main loop.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/ 
void tlkapp_handler(void);

/******************************************************************************
 * Function: tlkapp_pmIsBusy
 * Descript: user check is step into deepSleep_retention Mode or not.
 * Params: None.
 * Return: None.
 * Others: None.
*******************************************************************************/ 
bool tlkapp_pmIsBusy(void);



#endif /* TLKAPP_H */
