/*==========================================================
 * Copyright 2020 QuickLogic Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *==========================================================*/

/*==========================================================
 *
 *    File   : main.c
 *    Purpose: main for QuickFeather helloworldsw and LED/UserButton test
 *                                                          
 *=========================================================*/

#include "Fw_global_config.h"   // This defines application specific charactersitics

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "RtosTask.h"

/*    Include the generic headers required for QORC */
#include "eoss3_hal_gpio.h"
#include "eoss3_hal_rtc.h"
#include "eoss3_hal_timer.h"
#include "eoss3_hal_fpga_usbserial.h"
#include "ql_time.h"
#include "s3x_clock_hal.h"
#include "s3x_clock.h"
#include "s3x_pi.h"
#include "dbg_uart.h"

#include "cli.h"

#include "LCD16x2.h"
#include "LCD16x2_io.h"
#include "PyHal_GPIO.h"


const char *SOFTWARE_VERSION_STR;


/*
 * Global variable definition
 */


extern void qf_hardwareSetup();
static void nvic_init(void);

int main(void)
{

    SOFTWARE_VERSION_STR = "qorc-onion-apps/qf_hello-fpga-gpio-ctlr";
    HAL_Delay_Init();
    qf_hardwareSetup();
    nvic_init();

    dbg_str("\n\n");
    dbg_str( "##########################\n");
    dbg_str( "Quicklogic QuickFeather FPGA GPIO CONTROLLER EXAMPLE\n");
    dbg_str( "SW Version: ");
    dbg_str( SOFTWARE_VERSION_STR );
    dbg_str( "\n" );
    dbg_str( __DATE__ " " __TIME__ "\n" );
    dbg_str( "##########################\n\n");

    dbg_str( "\n\nHello Akhil, look at the LCD!!\n\n");	// <<<<<<<<<<<<<<<<<<<<<  Change me!
    
    PyHal_GPIO_SetDir(3,0); // output from ESP

    int out;	

    char i=0;
    LcdInit();dbg_str( "\ninit done\n");
    while(1){
        
        out = PyHal_GPIO_Get(3);
        
        if(out == 1){
            LcdClear();
            LcdWriteString("Logic HIGH");
            HAL_DelayUSec(200000);
        }
    	else{   
            LcdClear();
            LcdWriteString("Logic LOW");
            HAL_DelayUSec(200000);
        }
        
        // LcdClear();
        // LcdSetAddress(i++);
        // LcdWriteString("Nitish Babu ");
        // HAL_DelayUSec(200000);
        // LcdClear();
        // i = i<32?i:0;

    }
    
    /* Start the tasks and timer running. */
    // vTaskStartScheduler();
    dbg_str("PRINT DONE\n");

}

static void nvic_init(void)
 {
    // To initialize system, this interrupt should be triggered at main.
    // So, we will set its priority just before calling vTaskStartScheduler(), not the time of enabling each irq.
    NVIC_SetPriority(Ffe0_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(SpiMs_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(CfgDma_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(Uart_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(FbMsg_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
 }    

//needed for startup_EOSS3b.s asm file
void SystemInit(void)
{

}

//gpionum --> 0 --> 31 corresponding to the IO PADs
//gpioval --> 0 or 1
// #define FGPIO_DIRECTION_REG (0x40024008)
// #define FGPIO_OUTPUT_REG (0x40024004)

// void PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval)
// {
//     uint32_t tempscratch32;

//     if (gpionum > 31)
//         return;

//     tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);

//     *(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 | (0x1 << gpionum);

    
//     tempscratch32 = *(uint32_t*)(FGPIO_OUTPUT_REG);

//     if(gpioval > 0)
//     {
//         *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 | (0x1 << gpionum);
//     }
//     else
//     {
//         *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 & ~(0x1 << gpionum);
//     }    

//     return;
// }


