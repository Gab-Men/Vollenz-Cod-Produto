#include "hw_touch.h"

// ================== DEFINIÇÃO DOS PINOS ================== //
// Ajuste os PORTs (GPIOA, GPIOB...) conforme CubeMX

#define BTN_MENOS_TEMPO_PIN     GPIO_PIN_0
#define BTN_MENOS_TEMPO_PORT    GPIOA

#define BTN_MAIS_TEMPO_PIN      GPIO_PIN_1
#define BTN_MAIS_TEMPO_PORT     GPIOA

#define BTN_MENOS_PRESSAO_PIN   GPIO_PIN_2
#define BTN_MENOS_PRESSAO_PORT  GPIOA

#define BTN_MAIS_PRESSAO_PIN    GPIO_PIN_3
#define BTN_MAIS_PRESSAO_PORT   GPIOA

#define BTN_CAM1_PIN            GPIO_PIN_4
#define BTN_CAM1_PORT           GPIOA

#define BTN_CAM2_PIN            GPIO_PIN_5
#define BTN_CAM2_PORT           GPIOA

#define BTN_CAM3_PIN            GPIO_PIN_6
#define BTN_CAM3_PORT           GPIOA

#define BTN_CAM4_PIN            GPIO_PIN_7
#define BTN_CAM4_PORT           GPIOA

#define BTN_MODO_A_PIN          GPIO_PIN_8
#define BTN_MODO_A_PORT         GPIOA

#define BTN_MODO_B_PIN          GPIO_PIN_9
#define BTN_MODO_B_PORT         GPIOA

#define BTN_MODO_C_PIN          GPIO_PIN_10
#define BTN_MODO_C_PORT         GPIOA

#define BTN_MODO_D_PIN          GPIO_PIN_11
#define BTN_MODO_D_PORT         GPIOA

#define BTN_MODO_E_PIN          GPIO_PIN_12
#define BTN_MODO_E_PORT         GPIOA

#define BTN_MODO_F_PIN          GPIO_PIN_13
#define BTN_MODO_F_PORT         GPIOA

#define BTN_PAUSE_PIN           GPIO_PIN_14
#define BTN_PAUSE_PORT          GPIOA


// ================== INICIALIZAÇÃO ================== //
void hw_touch_init(void) {
    // Normalmente já configurado pelo CubeMX em MX_GPIO_Init()
    // Se precisar, aqui pode colocar debounce via software
}


// ================== LEITURA ================== //
TouchButton hw_touch_get(void) {
    if (HAL_GPIO_ReadPin(BTN_MENOS_TEMPO_PORT, BTN_MENOS_TEMPO_PIN) == GPIO_PIN_SET) return BTN_MENOS_TEMPO;
    if (HAL_GPIO_ReadPin(BTN_MAIS_TEMPO_PORT, BTN_MAIS_TEMPO_PIN) == GPIO_PIN_SET)   return BTN_MAIS_TEMPO;
    if (HAL_GPIO_ReadPin(BTN_MENOS_PRESSAO_PORT, BTN_MENOS_PRESSAO_PIN) == GPIO_PIN_SET) return BTN_MENOS_PRESSAO;
    if (HAL_GPIO_ReadPin(BTN_MAIS_PRESSAO_PORT, BTN_MAIS_PRESSAO_PIN) == GPIO_PIN_SET)   return BTN_MAIS_PRESSAO;

    if (HAL_GPIO_ReadPin(BTN_CAM1_PORT, BTN_CAM1_PIN) == GPIO_PIN_SET) return BTN_CAM1;
    if (HAL_GPIO_ReadPin(BTN_CAM2_PORT, BTN_CAM2_PIN) == GPIO_PIN_SET) return BTN_CAM2;
    if (HAL_GPIO_ReadPin(BTN_CAM3_PORT, BTN_CAM3_PIN) == GPIO_PIN_SET) return BTN_CAM3;
    if (HAL_GPIO_ReadPin(BTN_CAM4_PORT, BTN_CAM4_PIN) == GPIO_PIN_SET) return BTN_CAM4;

    if (HAL_GPIO_ReadPin(BTN_MODO_A_PORT, BTN_MODO_A_PIN) == GPIO_PIN_SET) return BTN_MODO_A;
    if (HAL_GPIO_ReadPin(BTN_MODO_B_PORT, BTN_MODO_B_PIN) == GPIO_PIN_SET) return BTN_MODO_B;
    if (HAL_GPIO_ReadPin(BTN_MODO_C_PORT, BTN_MODO_C_PIN) == GPIO_PIN_SET) return BTN_MODO_C;
    if (HAL_GPIO_ReadPin(BTN_MODO_D_PORT, BTN_MODO_D_PIN) == GPIO_PIN_SET) return BTN_MODO_D;
    if (HAL_GPIO_ReadPin(BTN_MODO_E_PORT, BTN_MODO_E_PIN) == GPIO_PIN_SET) return BTN_MODO_E;
    if (HAL_GPIO_ReadPin(BTN_MODO_F_PORT, BTN_MODO_F_PIN) == GPIO_PIN_SET) return BTN_MODO_F;

    if (HAL_GPIO_ReadPin(BTN_PAUSE_PORT, BTN_PAUSE_PIN) == GPIO_PIN_SET) return BTN_PAUSE;

    return BTN_NONE;
}
