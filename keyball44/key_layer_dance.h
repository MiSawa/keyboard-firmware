#pragma once

// Tap outside of `layer`   : tap `key_off_layer`
// Tap inside of `layer`    : tap `key_on_layer`
// Double tap               : turn on `layer`
// Triple tap               : turn off `layer`
// Hold outside of `layer`  : momentarily turn on `layer`
// keys can be KEY_NO to disable that tap.
#define ACTION_TAP_DANCE_KEY_LAYER(key_off_layer, key_on_layer, layer) \
    { .fn = {NULL, tap_dance_key_layer_finished, tap_dance_key_layer_reset}, .user_data = (void *)&((tap_dance_key_layer_data){key_off_layer, key_on_layer, layer, KC_NO, false}), }

typedef struct {
    uint16_t key_off_layer;
    uint16_t key_on_layer;
    uint16_t layer;
    uint16_t key_to_unregister;
    bool     should_leave_layer;
} tap_dance_key_layer_data;

void tap_dance_key_layer_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_key_layer_reset(tap_dance_state_t *state, void *user_data);
