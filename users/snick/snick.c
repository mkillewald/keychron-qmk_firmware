#include "snick.h"

void cycle_rgb_matrix_color(int count, int delay, uint8_t red, uint8_t green, uint8_t blue) {
    for (size_t i = 0; i < count; i++)
    {
        rgb_matrix_set_color_all(red, green, blue);
        rgb_matrix_driver.flush();
        wait_ms(delay);
        rgb_matrix_set_color_all(RGB_BLACK);
        rgb_matrix_driver.flush();
        wait_ms(delay);
    }
}

void keyboard_post_init_user(void) {
    // Do something after keyboard initialization
    rgb_matrix_set_color_all(RGB_BLUE);
    rgb_matrix_driver.flush();
    wait_ms(150);
}

// void suspend_power_down_user(void) {
//     // code will run multiple times while keyboard is suspended
//     // while(true) {
//         rgb_matrix_set_color_all(RGB_MAGENTA);
//         rgb_matrix_driver.flush();
//         wait_ms(500);
//     // };
// }

void suspend_wakeup_init_user(void) {
    // code will run on keyboard wakeup
    cycle_rgb_matrix_color(3, 50, RGB_GREEN);
}

// void eeconfig_init_user(void) {  // EEPROM is getting reset!

// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case QK_RESET: {
            if (record->event.pressed) {
                eeconfig_init();
                rgb_matrix_set_color_all(RGB_RED);
                rgb_matrix_driver.flush();
            }
            return true;
        }

        default:
            return true;  // Process all other keycodes normally
    }
}
