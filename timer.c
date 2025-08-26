// hw_timer.c
#include "stm8s.h"
#include "hw_timer.h"

static volatile uint32_t ms = 0;

void hw_timer_init(void) {
    // Timer4 para tick de 1 ms
    TIM4_PSCR = 0x07;
    TIM4_ARR = 125-1;
    TIM4_IER = 0x01;
    TIM4_CR1 = 0x01;
}

@far @interrupt void TIM4_UPD_OVF_IRQHandler(void) {
    TIM4_SR = 0;
    ms++;
}

uint32_t millis(void){ return ms; }

void pump_set_duty(uint16_t duty) {
    // PWM no TIM2 CH1 (exemplo)
    TIM2_CCR1H = (uint8_t)(duty >> 8);
    TIM2_CCR1L = (uint8_t)(duty & 0xFF);
}
