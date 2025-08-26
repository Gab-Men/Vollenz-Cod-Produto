#ifndef HW_SOLENOID_H
#define HW_SOLENOID_H

#include <stdint.h>

// Número de solenoides
#define SOLENOID_COUNT 4

// Inicializa GPIO dos solenoides
void Solenoid_Init(void);

// Liga solenoide específico (0 a 3)
void Solenoid_On(uint8_t id);

// Desliga solenoide específico
void Solenoid_Off(uint8_t id);

// Desliga todos
void Solenoid_AllOff(void);

#endif
