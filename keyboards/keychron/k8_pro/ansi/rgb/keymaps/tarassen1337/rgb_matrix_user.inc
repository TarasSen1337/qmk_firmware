// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(flag_ua)
RGB_MATRIX_EFFECT(blurple_grad)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "print.h"

// e.g: A simple effect, self-contained within a single method
static bool flag_ua(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  uint8_t half = 50;
  for (uint8_t i = led_min; i < half; i++) {
    rgb_matrix_set_color(i, 0x10, 0x10, 0xff);
  }
  for (uint8_t i = half; i < led_max; i++) {
    rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  }
  
  return led_max < DRIVER_LED_TOTAL;
}

static HSV blurple_grad_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = g_led_config.point[i].y - time;
    uint8_t color = hsv.h;
    if(hsv.h <= 127) color = 255 - hsv.h;
    color = ((color - 128) * 0.69) + 128;
    hsv.h = color;
    return hsv;
}

bool blurple_grad(effect_params_t* params) {
    return effect_runner_i(params, &blurple_grad_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS