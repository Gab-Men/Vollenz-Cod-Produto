#include "app.h"
#include "hw_touch.h"
#include "hw_solenoide.h"
#include "hw_bomba.h"
#include "hw_led.h"
#include "hw_buzzer.h"

static int timer = 30;
static int pressao = 30;
static uint8_t camara_enabled[4] = {1, 1, 1, 1};
// ---- LOOP PRINCIPAL ----
void app_loop(void) {
    TouchButton btn = hw_touch_get();

    switch (btn) {
        case BTN_MENOS_TEMPO:   diminuir_timer(); break;
        case BTN_MAIS_TEMPO:    aumentar_timer(); break;
        case BTN_MENOS_PRESSAO: diminuir_pressao(); break;
        case BTN_MAIS_PRESSAO:  aumentar_pressao(); break;
        case BTN_C1:            toggle_camara1(); break;
        case BTN_C2:            toggle_camara2(); break;
        case BTN_C3:            toggle_camara3(); break;
        case BTN_C4:            toggle_camara4(); break;
        case BTN_MODO_A:        selecionar_modoA(); break;
        case BTN_MODO_B:        selecionar_modoB(); break;
        case BTN_MODO_C:        selecionar_modoC(); break;
        case BTN_MODO_D:        selecionar_modoD(); break;
        case BTN_MODO_E:        selecionar_modoE(); break;
        case BTN_MODO_F:        selecionar_modoF(); break;
        case BTN_PAUSE:         pausar_ou_continuar(); break;
        default: break;
    }
}

// ---- CONTROLE DE TEMPO ----
void diminuir_timer() {
    if (timer > 0) {
        timer -= 1;
    } else {
        hw_buzzer_beep(200); // apita 200ms se j� estiver no m�nimo
    }
}

void aumentar_timer() {
    if (timer < 90) { // limite arbitr�rio
        timer += 1;
    } else {
        hw_buzzer_beep(200); // apita se j� estiver no m�ximo
    }
}

// ---- CONTROLE DE PRESS�O ----
void diminuir_pressao() {
    if (pressao <= 30) {
        hw_buzzer_beep(500); // apita se tentar descer abaixo do m�nimo
        return;
    }

    if (pressao == 150) {
        pressao -= 10;
    } else if (pressao == 140) {
        pressao -= 10;
    } else {
        pressao -= 5; // passo normal
    }
}

void aumentar_pressao() {
    if (pressao >= 150) {
        hw_buzzer_beep(500); // apita se tentar passar do limite
        return;
    }

    if (pressao == 130) {
        pressao += 10;
    } else if (pressao == 140) {
        pressao += 10;
    } else {
        return;// passo normal
    }
}

// ---- CONTROLE DE C�MARAS ----
// Exemplo gen�rico de toggle (liga/desliga)
void toggle_camara1() {
    if (hw_solenoide_is_on(1)) {
        hw_solenoide_off(1);
    } else {
        hw_solenoide_on(1);
    }
}

void toggle_camara2() {
    if (hw_solenoide_is_on(2)) {
        hw_solenoide_off(2);
    } else {
        hw_solenoide_on(2);
    }
}

void toggle_camara3() {
    if (hw_solenoide_is_on(3)) {
        hw_solenoide_off(3);
    } else {
        hw_solenoide_on(3);
    }
}

void toggle_camara4() {
    if (hw_solenoide_is_on(4)) {
        hw_solenoide_off(4);
    } else {
        hw_solenoide_on(4);
    }
}

void set_camara(uint8_t id, uint8_t on) {
    if (camara_enabled[id-1] == 0) {
        hw_solenoide_off(id); // se usu�rio desligou manualmente, n�o deixa ligar
        return;
    }
    if (on) {
        hw_solenoide_on(id);
    } else {
        hw_solenoide_off(id);
    }
}

void reset_camaras_enabled() {
    for (int i = 0; i < 4; i++) {
        camara_enabled[i] = 1; // volta todas como ligadas quando troca de modo
    }
}

// ---- BOT�ES DE TOGGLE ----
void toggle_camara1() { camara_enabled[0] = !camara_enabled[0]; hw_solenoide_off(1); }
void toggle_camara2() { camara_enabled[1] = !camara_enabled[1]; hw_solenoide_off(2); }
void toggle_camara3() { camara_enabled[2] = !camara_enabled[2]; hw_solenoide_off(3); }
void toggle_camara4() { camara_enabled[3] = !camara_enabled[3]; hw_solenoide_off(4); }

// ---- MODOS DE OPERA��O ----
// cada delay = 15s (pode ajustar)
#define STEP_TIME 15000

void selecionar_modoA() {
    reset_camaras_enabled();

    while (1) { // loop at� pausar/parar
        set_camara(1, 1); delay(STEP_TIME);
        set_camara(2, 1); delay(STEP_TIME);
        set_camara(3, 1); delay(STEP_TIME);
        set_camara(4, 1); delay(STEP_TIME);

        // reset para pr�xima sequ�ncia
        hw_solenoide_off(1);
        hw_solenoide_off(2);
        hw_solenoide_off(3);
        hw_solenoide_off(4);
    }
}

void selecionar_modoB() {
    reset_camaras_enabled();

    while (1) {
        set_camara(1, 1); delay(STEP_TIME);
        set_camara(2, 1); delay(STEP_TIME);
        set_camara(3, 1); delay(STEP_TIME);
        set_camara(4, 1); delay(STEP_TIME);

        // no modo B a diferen�a � que a anterior desliga quando a pr�xima liga
        hw_solenoide_off(1);
        hw_solenoide_off(2);
        hw_solenoide_off(3);
        hw_solenoide_off(4);
    }
}

void selecionar_modoC() {
    reset_camaras_enabled();

    while (1) {
        set_camara(1, 1); set_camara(2, 1); delay(STEP_TIME);
        set_camara(3, 1); set_camara(4, 1); delay(STEP_TIME);

        hw_solenoide_off(1);
        hw_solenoide_off(2);
        hw_solenoide_off(3);
        hw_solenoide_off(4);
    }
}

void selecionar_modoD() {
    reset_camaras_enabled();

    while (1) {
        set_camara(4, 1); delay(STEP_TIME);
        set_camara(3, 1); delay(STEP_TIME);
        set_camara(2, 1); delay(STEP_TIME);
        set_camara(1, 1); delay(STEP_TIME);

        hw_solenoide_off(1);
        hw_solenoide_off(2);
        hw_solenoide_off(3);
        hw_solenoide_off(4);
    }
}

void selecionar_modoE() {
    reset_camaras_enabled();

    while (1) {
        set_camara(1, 1); set_camara(3, 1); delay(STEP_TIME);
        set_camara(2, 1); set_camara(4, 1); delay(STEP_TIME);

        hw_solenoide_off(1);
        hw_solenoide_off(2);
        hw_solenoide_off(3);
        hw_solenoide_off(4);
    }
}

void selecionar_modoF() {
    reset_camaras_enabled();

    while (1) {
        set_camara(1, 1); set_camara(4, 1); delay(STEP_TIME);
        set_camara(2, 1); set_camara(3, 1); delay(STEP_TIME);

        hw_solenoide_off(1);
        hw_solenoide_off(2);
        hw_solenoide_off(3);
        hw_solenoide_off(4);
    }
}

// ---- PAUSE ----
static uint8_t paused = 0;

void pausar_ou_continuar() {
    paused = !paused;
    if (paused) {
        hw_buzzer_beep(300);
        hw_solenoide_off(1);
        hw_solenoide_off(2);
        hw_solenoide_off(3);
        hw_solenoide_off(4);
    } else {
        hw_buzzer_beep(100);
    }
}
