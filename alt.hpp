#ifndef ALT_H
#define ALT_H

#include <Keyboard.h>
#include <stdint.h>

#define BEGIN()           \
    void setup() {        \
        Keyboard.begin(); \
        delay(1000);

#define END()       \
    Keyboard.end(); \
    }               \
    void loop() {}

#define KPRINT(msg) Keyboard.print((msg));
#define KPRESS(msg) Keyboard.press((msg));
#define KRELALL() Keyboard.releaseAll();
#define KREL(key) Keyboard.release((key));
#define WAIT(ms) delay((ms));

#define CHECK_MASK(original, n, mask) ((original) & (1 << (n))) == (mask)

#define MKEY_LEFT_CTRL (0x0001 << 0x00)
#define MKEY_LEFT_WIN (0x0001 << 0x01)
#define MKEY_LEFT_SHIFT (0x0001 << 0x02)
#define MKEY_LEFT_ALT (0x0001 << 0x03)
#define MKEY_ENTER (0x0001 << 0x04)

#define MKEY_LEFT_ARROW (0x0001 << 0x05)
#define MKEY_RIGHT_ARROW (0x0001 << 0x06)

#define MKEY_CH_R (0x0001 << 0x07)
#define MKEY_CH_A (0x0001 << 0x08)
#define MKEY_CH_C (0x0001 << 0x09)

#define MKEY_FN_4 (0x0001 << 0x0A)

#define MKEY_CH_Y (0x0001 << 0x0B)

typedef struct {
    char symbol;
    uint8_t code;
} alt_code;

// 0..9 numpad keys
static const uint8_t numpad_keys[] = {0xEA, 0xE1, 0xE2, 0xE3, 0xE4,
                                      0xE5, 0xE6, 0xE7, 0xE8, 0xE9};

static const alt_code alt_codes_array[] = {
    {' ', 32},  {'B', 66},  {'C', 67},  {'D', 68},  {'E', 69},  {'F', 70},
    {'G', 71},  {'H', 72},  {'I', 73},  {'J', 74},  {'K', 75},  {'L', 76},
    {'M', 77},  {'N', 78},  {'O', 79},  {'P', 80},  {'Q', 81},  {'R', 82},
    {'S', 83},  {'T', 84},  {'U', 85},  {'V', 86},  {'W', 87},  {'X', 88},
    {'Y', 89},  {'Z', 90},  {'a', 97},  {'b', 98},  {'c', 99},  {'d', 100},
    {'e', 101}, {'f', 102}, {'g', 103}, {'h', 104}, {'i', 105}, {'j', 106},
    {'k', 107}, {'l', 108}, {'m', 109}, {'n', 110}, {'o', 111}, {'p', 112},
    {'q', 113}, {'r', 114}, {'s', 115}, {'t', 116}, {'u', 117}, {'v', 118},
    {'w', 119}, {'x', 120}, {'y', 121}, {'z', 122}, {'0', 48},  {'1', 49},
    {'2', 50},  {'3', 51},  {'4', 52},  {'5', 53},  {'6', 54},  {'7', 55},
    {'8', 56},  {'9', 57},  {'!', 33},  {'"', 34},  {'#', 35},  {'$', 36},
    {'%', 37},  {'&', 38},  {'\'', 39}, {'(', 40},  {')', 41},  {'*', 42},
    {'+', 43},  {',', 44},  {'-', 45},  {'.', 46},  {'/', 47},  {':', 58},
    {';', 59},  {'<', 60},  {'=', 61},  {'>', 62},  {'?', 63},  {'@', 64},
    {'[', 91},  {'\\', 92}, {']', 93},  {'^', 94},  {'_', 95},  {'`', 96},
    {'{', 123}, {'|', 124}, {'}', 125}, {'~', 126}, {'A', 65}};

static constexpr int alt_codes_n =
    sizeof(alt_codes_array) / sizeof(*alt_codes_array);

// buff = 4 * uint8_t (i3 = count numbers)
static void get_alt_code(uint8_t *buff, uint8_t num) {
    buff[3] = 0;
    while (num != 0) {
        buff[buff[3]] = num % 10;
        num /= 10;
        buff[3]++;
    }
}

static uint8_t get_full_code(char c) {
    for (int i = 0; i < alt_codes_n; i++) {
        if (alt_codes_array[i].symbol == c) {
            return alt_codes_array[i].code;
        }
    }

    return 0;
}

static void alt_print(const char *str, size_t t_sleep) {
    const int s_len = static_cast<int>(strlen(str));
    static uint8_t buff[4];
    uint8_t code = 0;

    for (int i = 0; i < s_len; ++i) {
        KPRESS(KEY_LEFT_ALT)
        delay(t_sleep);

        if (!(code = get_full_code(str[i]))) goto EXT;
        get_alt_code(buff, code);

        // buff[3] = count numbers in alt code
        for (int j = static_cast<int>(buff[3] - 1); j >= 0; j--) {
            KPRESS(numpad_keys[buff[j]])
            KREL(numpad_keys[buff[j]])
        }
    EXT:
        KREL(KEY_LEFT_ALT)
    }
}

static void tprint(const char *str, size_t t_sleep) {
    const int s_len = static_cast<int>(strlen(str));

    for (int i = 0; i < s_len; ++i) {
        Keyboard.write(str[i]);
        delay(t_sleep);
    }
}

static const uint16_t btn_arr[] = {
    MKEY_LEFT_CTRL,  MKEY_LEFT_WIN,    MKEY_LEFT_SHIFT,
    MKEY_LEFT_ALT,   MKEY_ENTER,

    MKEY_LEFT_ARROW, MKEY_RIGHT_ARROW,

    MKEY_CH_R,       MKEY_CH_A,        MKEY_CH_C,

    MKEY_FN_4, MKEY_CH_Y};

static const uint8_t btn_value_arr[] = {KEY_LEFT_CTRL,
                                        KEY_LEFT_GUI,
                                        KEY_LEFT_SHIFT,
                                        KEY_LEFT_ALT,
                                        KEY_RETURN,

                                        KEY_LEFT_ARROW,
                                        KEY_RIGHT_ARROW,

                                        'r',
                                        'a',
                                        'c',

                                        KEY_F4, 'y'};

static constexpr int BTN_N = sizeof(btn_value_arr) / sizeof(*btn_value_arr);

static bool release_btn(const uint8_t button) {
    for (int i = 0; i < BTN_N; ++i) {
        if (btn_arr[i] == button) {
            KREL(btn_value_arr[i])
            return true;
        }
    }

    return false;
}

// (int i = BTN_N-1; i >= 0; i--)
#define PRESS(BTNS, t_sleep)                     \
    for (int i = 0; i < BTN_N; i++) {            \
        if (CHECK_MASK((BTNS), i, btn_arr[i])) { \
            KPRESS(btn_value_arr[i]);            \
            WAIT(t_sleep)                        \
        }                                        \
    }

#define PRESS_KRELALL(BTNS, t_sleep, t_wait) \
    PRESS((BTNS), t_sleep)                   \
    WAIT(t_wait)                             \
    KRELALL()
 
#define RUN_ENTER(command, t_sleep_print)              \
    PRESS_KRELALL(MKEY_LEFT_WIN | MKEY_CH_R, 200, 300) \
    alt_print((command), (t_sleep_print));             \
    WAIT(200)                                          \
    PRESS_KRELALL(MKEY_ENTER, 0, 300)                  \
    WAIT(500)

#define RUN_ENTER_AS_ADMIN(command, t_sleep_print)                       \
    PRESS_KRELALL(MKEY_LEFT_WIN | MKEY_CH_R, 200, 300)                   \
    alt_print((command), (t_sleep_print));                               \
    WAIT(200)                                                            \
    PRESS_KRELALL(MKEY_LEFT_CTRL | MKEY_LEFT_SHIFT | MKEY_ENTER, 0, 300) \
    WAIT(900)                                                            \
    PRESS_KRELALL(MKEY_LEFT_ALT | MKEY_CH_Y, 0, 200)                     \
    WAIT(500)

#endif  // ALT_H
