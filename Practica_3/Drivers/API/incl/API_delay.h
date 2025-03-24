
#ifndef _API_DELAY_
#define _API_DELAY_

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

// Punto 3 - patrón de parpadeo
typedef struct {
    tick_t period;      // Periodo total en ms
    tick_t dutyCycle;   // Tiempo encendido en ms (ciclo de trabajo)
    uint8_t repeat;     // Cantidad de repeticiones del patrón
} blinkPattern_t;

void   delayInit  ( delay_t * delay, tick_t duration );
void   delayWrite ( delay_t * delay, tick_t duration );
bool_t delayRead  ( delay_t * delay );

#endif
