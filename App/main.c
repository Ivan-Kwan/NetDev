/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */


/******************************************************************************
/* * Project: Personal FreeRTOS Research
 * Author: Ivan Kwan
 * Location: London, Ontario
 * Target: Cortex-M3 (QEMU Simulation)
 */

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "intf_uart.h"

void vNetTask(void *pvParameters) {
    for(;;) {
        intfUartPrint("[App] Running on virtual Cortex-M3...\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void) {
    /* Initialize via Interface layer */
    intfUartInit();
    
    xTaskCreate(vNetTask, "App_Task", 1024, NULL, 1, NULL);
    vTaskStartScheduler();
    
    for(;;);
    return 0;
}

/* -------------------------------------------------------
 * Mandatory FreeRTOS Hooks (Required by Linker)
 * ------------------------------------------------------- */

/* 1. vAssertCalled: Required by configASSERT */
void vAssertCalled(const char * pcFileName, uint32_t ulLine)
{
    printf("ASSERT FAILED! File: %s, Line: %u\r\n", pcFileName, (unsigned int)ulLine);
    taskDISABLE_INTERRUPTS();
    for(;;);
}

/* 2. vApplicationTickHook: Required if configUSE_TICK_HOOK is 1 */
void vApplicationTickHook(void)
{
    /* This runs every clock tick (e.g., every 1ms) */
}

/* 3. vApplicationMallocFailedHook: Required if configUSE_MALLOC_FAILED_HOOK is 1 */
void vApplicationMallocFailedHook(void)
{
    vAssertCalled("Malloc Failed", 0);
}

/* 4. vApplicationStackOverflowHook: Required if configCHECK_FOR_STACK_OVERFLOW > 0 */
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    ( void ) pxTask;
    printf("Stack Overflow in task: %s\r\n", pcTaskName);
    vAssertCalled("Stack Overflow", 0);
}

/* 5. Static Allocation Hooks: Required by configSUPPORT_STATIC_ALLOCATION */

/* Provide memory for the Idle Task */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize)
{
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/* Provide memory for the Timer Task */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
                                    StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize)
{
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}