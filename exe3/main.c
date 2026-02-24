#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdbool.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTNR_PIN  = 28;
const int BTNG_PIN  = 26;

int main(void) {
  stdio_init_all();

  // Botões (entrada com pull-up)
  gpio_init(BTNR_PIN);
  gpio_set_dir(BTNR_PIN, GPIO_IN);
  gpio_pull_up(BTNR_PIN);

  gpio_init(BTNG_PIN);
  gpio_set_dir(BTNG_PIN, GPIO_IN);
  gpio_pull_up(BTNG_PIN);

  // LEDs (saída)
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_put(LED_PIN_R, 0);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  gpio_put(LED_PIN_G, 0);

  bool red_on = false;
  bool green_on = false;

  while (true) {
    if (!gpio_get(BTNR_PIN)) {
      red_on = !red_on;
      gpio_put(LED_PIN_R, red_on);
      while (!gpio_get(BTNR_PIN)) { } // espera soltar
    }

    if (!gpio_get(BTNG_PIN)) {
      green_on = !green_on;
      gpio_put(LED_PIN_G, green_on);
      while (!gpio_get(BTNG_PIN)) { } // espera soltar
    }
  }

  return 0;
}