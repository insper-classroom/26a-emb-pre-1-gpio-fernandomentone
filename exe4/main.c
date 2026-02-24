#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTNR_PIN  = 28;
const int LED_PIN_R = 5;
const int LED_PIN_P = 8;
const int LED_PIN_B = 11;
const int LED_PIN_Y = 15;

static void all_off(void) {
  gpio_put(LED_PIN_R, 0);
  gpio_put(LED_PIN_P, 0);
  gpio_put(LED_PIN_B, 0);
  gpio_put(LED_PIN_Y, 0);
}

int main(void) {
  stdio_init_all();

  gpio_init(BTNR_PIN);
  gpio_set_dir(BTNR_PIN, GPIO_IN);
  gpio_pull_up(BTNR_PIN);

  gpio_init(LED_PIN_P);
  gpio_set_dir(LED_PIN_P, GPIO_OUT);

  gpio_init(LED_PIN_B);
  gpio_set_dir(LED_PIN_B, GPIO_OUT);

  gpio_init(LED_PIN_Y);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  all_off();

  while (true) {
    if (!gpio_get(BTNR_PIN)) {
      while (!gpio_get(BTNR_PIN)) {}

      all_off();
      gpio_put(LED_PIN_R, 1);
      sleep_ms(300);

      all_off();
      gpio_put(LED_PIN_P, 1);
      sleep_ms(300);

      all_off();
      gpio_put(LED_PIN_B, 1);
      sleep_ms(300);

      all_off();
      gpio_put(LED_PIN_Y, 1);
      sleep_ms(300);

      all_off();
    }
  }
  return 0;
}
