#include "color.h"
#include "print.h"
#include "quantum/rgb_matrix/rgb_matrix.h"

//HSV Matrix Functions

void set_matrix_col_hsv(HSV hsv) {
    rgb_matrix_config.hsv = hsv;
    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
}

void set_matrix_col_hsv_individual(uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {
        .h = h,
        .s = s,
        .v = v,
    };
    set_matrix_col_hsv(hsv);
}

void set_matrix_col_hsv_arr(uint8_t hsv_array[3]) {
    set_matrix_col_hsv_individual(hsv_array[0], hsv_array[1], hsv_array[2]);
}

//RGB Matrix Functions

void set_matrix_col_rgb(RGB rgb) {
    // HSV hsv = rgb_to_hsv(rgb);
    // set_matrix_col_hsv(hsv);
}

void set_matrix_col_rgb_individual(uint8_t r, uint8_t g, uint8_t b) {
    RGB rgb = {
        .r = r,
        .g = g,
        .b = b,
    };
    set_matrix_col_rgb(rgb);
}

void set_matrix_col_rgb_arr(uint8_t rgb_array[3]) {
    set_matrix_col_rgb_individual(rgb_array[0], rgb_array[1], rgb_array[2]);
}
