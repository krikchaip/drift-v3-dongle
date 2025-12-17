#include <zephyr/kernel.h>

#include <zmk/event_manager.h>
#include <zmk/events/keycode_state_changed.h>
#include <zmk/hid.h>

/* Track physical state */
static bool a_down = false;
static bool d_down = false;

/* Track what ZMK thinks is currently active */
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

    /* ---- A pressed ---- */
    if (kc == HID_USAGE_KEY_KEYBOARD_A && pressed) {
        a_down = true;

        if (d_active) {
            d_active = false;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_D, false,
                                            ev->timestamp);
        }

        if (!a_active) {
            a_active = true;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_A, true,
                                            ev->timestamp);
        }

        return ZMK_EV_EVENT_HANDLED;
    }

    /* ---- A released ---- */
    if (kc == HID_USAGE_KEY_KEYBOARD_A && !pressed) {
        a_down = false;

        if (a_active) {
            a_active = false;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_A, false,
                                            ev->timestamp);
        }

        if (d_down && !d_active) {
            d_active = true;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_D, true,
                                            ev->timestamp);
        }

        return ZMK_EV_EVENT_HANDLED;
    }

    /* ---- D pressed ---- */
    if (kc == HID_USAGE_KEY_KEYBOARD_D && pressed) {
        d_down = true;

        if (a_active) {
            a_active = false;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_A, false,
                                            ev->timestamp);
        }

        if (!d_active) {
            d_active = true;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_D, true,
                                            ev->timestamp);
        }

        return ZMK_EV_EVENT_HANDLED;
    }

    /* ---- D released ---- */
    if (kc == HID_USAGE_KEY_KEYBOARD_D && !pressed) {
        d_down = false;

        if (d_active) {
            d_active = false;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_D, false,
                                            ev->timestamp);
        }

        if (a_down && !a_active) {
            a_active = true;
            raise_zmk_keycode_state_changed(HID_USAGE_KEY_KEYBOARD_A, true,
                                            ev->timestamp);
        }

        return ZMK_EV_EVENT_HANDLED;
    }

    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(smooth_strafe, smooth_strafe_listener);
ZMK_SUBSCRIPTION(smooth_strafe, zmk_keycode_state_changed);