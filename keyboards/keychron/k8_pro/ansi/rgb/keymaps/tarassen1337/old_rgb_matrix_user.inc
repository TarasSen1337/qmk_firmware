RGB_MATRIX_EFFECT(blurple_gradient)
RGB_MATRIX_EFFECT(half_gradient)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// bool blurple_gradient(effect_params_t* params){
//     RGB_MATRIX_USE_LIMITS(led_min, led_max);
//     HSV     hsv   = rgb_matrix_config.hsv;
//     uint8_t scale = scale8(64, rgb_matrix_config.speed);
//     for (uint8_t i = led_min; i < led_max; i++) {
//         RGB_MATRIX_TEST_LED_FLAGS();
//         // The y range will be 0..64, map this to 0..4
//         // Relies on hue being 8-bit and wrapping
//         hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);
//         uint8_t hue = hsv.h;
//         if(hue > 300 || hue < 180){
//           hue = hue/2;
//           hue = 360 - hue;
//         }
//         hsv.h = hue;
//         RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
//         rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//     }
//     return rgb_matrix_check_finished_leds(led_max);
// }

bool blurple_gradient(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV     hsv   = rgb_matrix_config.hsv;
    uint8_t scale = scale8(64, rgb_matrix_config.speed);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        // The y range will be 0..64, map this to 0..4
        // Relies on hue being 8-bit and wrapping
        hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

// bool half_gradient(effect_params_t* params){
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV     hsv   = rgb_matrix_config.hsv;
    uint8_t scale = scale8(64, rgb_matrix_config.speed);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        // The y range will be 0..64, map this to 0..4
        // Relies on hue being 8-bit and wrapping
        hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);
        uint8_t hue = hsv.h;
        if(340 < hue && hue < 360){
          hue = 340 - (hue - 340);
        } else
          if(0 <= hue &&hue < 160){
            hue = 340 - (hue + 20);
        }
        hsv.h = hue;
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool half_gradient(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV     hsv   = rgb_matrix_config.hsv;
    uint8_t scale = scale8(64, rgb_matrix_config.speed);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        // The y range will be 0..64, map this to 0..4
        // Relies on hue being 8-bit and wrapping
        hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);
        hsv.h = hsv.h / 2;
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif