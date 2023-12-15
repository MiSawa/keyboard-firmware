#include "quantum.h"

#include "key_layer_dance.h"

void tap_dance_key_layer_finished(tap_dance_state_t *const state, void *const user_data) {
    tap_dance_key_layer_data *const dance_data = (tap_dance_key_layer_data *)user_data;
    dance_data->key_to_unregister              = KC_NO;
    dance_data->should_leave_layer             = false;
    const bool is_tap                          = state->interrupted || !state->pressed;
    const bool in_layer                        = layer_state_is(dance_data->layer);
    if (is_tap) {
        if (state->count == 1) {
            // single tap
            const uint16_t key = in_layer ? dance_data->key_on_layer : dance_data->key_off_layer;
            if (key != KC_NO) {
                register_code16(key);
                dance_data->key_to_unregister = key;
            }
        } else if (state->count == 2) {
            // double tap
            layer_on(dance_data->layer);
        } else {
            // triple tap or more
            layer_off(dance_data->layer);
        }
    } else {
        // hold
        if (!in_layer) {
            layer_on(dance_data->layer);
            dance_data->should_leave_layer = true;
        }
    }
}

void tap_dance_key_layer_reset(tap_dance_state_t *const state, void *const user_data) {
    tap_dance_key_layer_data *dance_data = (tap_dance_key_layer_data *)user_data;
    if (dance_data->key_to_unregister != KC_NO) {
        unregister_code16(dance_data->key_to_unregister);
        dance_data->key_to_unregister = KC_NO;
    }
    if (dance_data->should_leave_layer) {
        layer_off(dance_data->layer);
        dance_data->should_leave_layer = false;
    }
}
