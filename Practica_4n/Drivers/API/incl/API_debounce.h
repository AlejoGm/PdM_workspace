/*
 * API_debounce.h
 *
 *  Created on: Mar 27, 2025
 *      Author: User
 */

#ifndef API_INCL_API_DEBOUNCE_H_
#define API_INCL_API_DEBOUNCE_H_

#include <stdint.h>
#include <stdbool.h>

bool readKey();
void debounceFSM_init();
void debounceFSM_update();


#endif /* API_INCL_API_DEBOUNCE_H_ */
