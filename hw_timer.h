// hw_timer.h
#ifndef HW_TIMER_H
#define HW_TIMER_H
void hw_timer_init(void);
void pump_set_duty(uint16_t duty);
uint32_t millis(void);
#endif
