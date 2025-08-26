#ifndef HW_TOUCH_H
#define HW_TOUCH_H

#include "stm32f1xx_hal.h"   // ou seu modelo exato de STM32

typedef enum {
    BTN_NONE = 0,
    BTN_MENOS_TEMPO,
    BTN_MAIS_TEMPO,
    BTN_MENOS_PRESSAO,
    BTN_MAIS_PRESSAO,
    BTN_CAM1,
    BTN_CAM2,
    BTN_CAM3,
    BTN_CAM4,
    BTN_MODO_A,
    BTN_MODO_B,
    BTN_MODO_C,
    BTN_MODO_D,
    BTN_MODO_E,
    BTN_MODO_F,
    BTN_PAUSE
} TouchButton;

void hw_touch_init(void);
TouchButton hw_touch_get(void);

#endif
