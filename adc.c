// hw_adc.c
#include "stm8s.h"
#include "hw_adc.h"

void hw_adc_init(void) {
    ADC1_CR1 = 0x01;
    ADC1_CR2 = 0x08; // right align
}

uint16_t adc_read(void) {
    ADC1_CSR = (ADC1_CSR & 0xF0) | 2; // canal PC4
    ADC1_CR1 |= 0x01;
    while(!(ADC1_CSR & 0x80));
    uint16_t v = ((uint16_t)ADC1_DRH<<8) | ADC1_DRL;
    ADC1_CSR &= ~0x80;
    return v;
}
