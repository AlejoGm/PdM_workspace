/*
 * API_uart.h
 *
 *  Created on: Apr 3, 2025
 *      Author: User
 */

#ifndef API_UART_H_
#define API_UART_H_

#include <stdint.h>
#include <stdbool.h>

bool uartInit();
void uartSendString(const char * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);


#endif /* API_UART_H_ */
