// hw_gpio.c
#include "stm8s.h"
#include "hw_gpio.h"

void hw_gpio_init(void) {
    // Exemplo: LED em PC3
    PC_DDR |= (1<<3); 
    PC_CR1 |= (1<<3); 
    PC_ODR &= ~(1<<3);
}
