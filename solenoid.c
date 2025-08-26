#include "hw_solenoid.h"
#include "stm8s.h"   // cabeçalho do STM8 (SDCC)

// Defina aqui quais pinos vão para cada solenoide
// Exemplo: Solenoides conectados em PortD, pinos 0-3
#define SOLENOID_PORT   GPIOD

void Solenoid_Init(void)
{
    // Configura pinos como saída push-pull
    GPIO_Init(SOLENOID_PORT, GPIO_PIN_0, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(SOLENOID_PORT, GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(SOLENOID_PORT, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(SOLENOID_PORT, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);

    Solenoid_AllOff();
}

void Solenoid_On(uint8_t id)
{
    switch(id) {
        case 0: GPIO_WriteHigh(SOLENOID_PORT, GPIO_PIN_0); break;
        case 1: GPIO_WriteHigh(SOLENOID_PORT, GPIO_PIN_1); break;
        case 2: GPIO_WriteHigh(SOLENOID_PORT, GPIO_PIN_2); break;
        case 3: GPIO_WriteHigh(SOLENOID_PORT, GPIO_PIN_3); break;
    }
}

void Solenoid_Off(uint8_t id)
{
    switch(id) {
        case 0: GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_0); break;
        case 1: GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_1); break;
        case 2: GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_2); break;
        case 3: GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_3); break;
    }
}

void Solenoid_AllOff(void)
{
    GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_0);
    GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_1);
    GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_2);
    GPIO_WriteLow(SOLENOID_PORT, GPIO_PIN_3);
}
