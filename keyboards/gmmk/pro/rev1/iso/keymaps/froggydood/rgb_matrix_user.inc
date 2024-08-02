
// RGB_MATRIX_EFFECT(snake)

// #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// // static uint8_t r1 = 255;
// // static uint8_t g1 = 89;
// // static uint8_t b1 = 98;

// HSV snake_col = {
//     .h = 94,
//     .s = 138,
//     .v = 110
// };

// HSV food_col = {
//     .h = 0,
//     .s = 255,
//     .v = 128
// };

// int map[] = {
//     14,
//     15,
//     15,
//     15,
//     15,
//     10
// };

// int position[2] = {0, 0};

// static bool snake_init(effect_params_t* params) {
//     // set_matrix_col_hsv_individual(0,0,0);

//     return led_max < DRIVER_LED_TOTAL;
// }

// static bool snake_run(effect_params_t* params) {

//     return led_max < DRIVER_LED_TOTAL;
// }

// static bool snake(effect_params_t* params) {
//     RGB_MATRIX_USE_LIMITS(led_min, led_max);
//     if (params->init) return snake_init(params);
//     return snake_run(params);
// }

// #endif
