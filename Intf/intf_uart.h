/* * File: intf_uart.h
 * Purpose: Provide a generic interface for serial communication.
 */
#ifndef INTF_UART_H
#define INTF_UART_H

/* Generic initialization function */
void intfUartInit(void);

/* Generic print function that hides hardware details */
void intfUartPrint(const char *pcString);

#endif