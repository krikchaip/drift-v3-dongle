#include <zephyr/kernel.h>

#include <zmk/event_manager.h>
#include <zmk/events/keycode_state_changed.h>
#include <zmk/hid.h>

/* ZMK-encoded keycodes */
#define KC_A ZMK_HID_USAGE(HID_USAGE_KEYBOARD, HID_USAGE_KEY_KEYBOARD_A)
#define KC_D ZMK_HID_USAGE(HID_USAGE_KEYBOARD, HID_USAGE_KEY_KEYBOARD_D)

/* Physical state */
static bool a_down = false;
static bool d_down = false;

/* Active (synthetic) state */
static bool a_active = false;
static bool d_active = false;

static int smooth_strafe_listener(const zmk_event_t *eh) {
    const struct zmk_keycode_state_changed *ev =
        as_zmk_keycode_state_changed(eh);

    if (!ev) {
        return ZMK_EV_EVENT_BUBBLE;
    }

    uint32_t kc = ev->keycode;
    bool pressed = ev->state;

    /* ---------- A pressed ---------- */
    if (kc == KC_A && pressed) {
        a_down = true;

        if (d_active) {
            d_active = false;
            raise_zmk_keycode_state_changed_from_encoded(
                KC_D, false, ev->timestamp);
        }

        if (!a_active) {
            a_active = true;
            raise_zmk_keycode_state_changed_from_encoded(
                KC_A, true, ev->timestamp);
        }

        return ZMK_EV_EVENT_HANDLED;
    }

    /* ---------- A released ---------- */
    if (kc == KC_A && !pressed) {
        a_down = false;

        if (a_active) {
            a_active = false;
            raise_zmk_keycode_state_changed_from_encoded(
                KC_A, false, ev->timestamp);
        }

        if (d_down && !d_active) {
            d_active = true;
            raise_zmk_keycode_state_changed_from_encoded(
                KC_D, true, ev->timestamp);
        }

        return ZMK_EV_EVENT_HANDLED;
    }

    /* ---------- D pressed ---------- */
    if (kc == KC_D && pressed) {
        d_down = true;

        if (a_active) {
            a_active = false;
            raise_zmk_keycode_state_changed_from_encoded(
                KC_A, false, ev->timestamp);
        }

        if (!d_active) {
            d_active = true;
            raise_zmk_keycode_state_changed_from_encoded(
                KC_D, true, ev->timestamp);
        }

        return ZMK_EV_EVENT_HANDLED;
    }

    /* ---------- D released ---------- */
    if (kc == KC_D && !pressed) {
