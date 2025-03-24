# Práctica 3 - 🕒 STM32 Delay No Bloqueante

Implementa un módulo de software para trabajar con retardos no bloqueantes a partir de las funciones creadas en la práctica 2.
Para placa de desarrollo **STM32 Nucleo-F446RE**

## ✅ Funciones implementadas

- `delayInit()`  
  Inicializa una estructura `delay_t` con duración definida.

- `delayRead()`  
  Verifica si el tiempo del retardo se cumplió. Si no está corriendo, lo inicia.

- `delayWrite()`  
  Cambia la duración del retardo sin reiniciarlo.

- `delayIsRunning()`  
  Devuelve si un retardo está actualmente activo (`running == true`).

## Autor
Proyecto realizado por Alejo Garcia Mata




