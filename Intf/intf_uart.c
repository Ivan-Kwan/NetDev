/* * File: intf_uart.c
 * Implementation for Cortex-M3 QEMU platform.
 */
#include <stdio.h>
#include "intf_uart.h"

void intfUartInit(void) {
    /* Hardware specific init code would go here */
    // Todo
}

void intfUartPrint(const char *pcString) {
    printf("%s", pcString);
}