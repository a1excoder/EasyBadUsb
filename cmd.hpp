#include <Keyboard.h>
#include <stdint.h>

#define BEGIN \
  void setup() { \
  Keyboard.begin(KeyboardLayout_en_US); \
  delay(1000);

#define END \
    Keyboard.end();} \
  void loop() {}


#define MKEY_LEFT_CTRL     0x00000001
#define MKEY_LEFT_WIN      0x00000002
#define MKEY_LEFT_SHIFT    0x00000004
#define MKEY_LEFT_ALT      0x00000008
#define MKEY_ENTER         0x00000010

#define MKEY_UP_ARROW      0x00000020
#define MKEY_DOWN_ARROW    0x00000040
#define MKEY_LEFT_ARROW    0x00000080
#define MKEY_RIGHT_ARROW   0x00000100

#define MKEY_BACKSPACE     0x00000200
#define MKEY_TAB           0x00000400

#define MKEY_CH_R          0x00000800
#define MKEY_CH_A          0x00001000
#define MKEY_CH_C          0x00002000

#define MKEY_ESC           0x00004000
#define MKEY_CAPS_LOCK     0x00008000
#define MKEY_PRINT_SCREEN  0x00010000
#define MKEY_FN            0x00020000

#define MKEY_NUM_0         0x00040000
#define MKEY_NUM_1         0x00080000
#define MKEY_NUM_2         0x00100000
#define MKEY_NUM_3         0x00200000
#define MKEY_NUM_4         0x00400000
#define MKEY_NUM_5         0x00800000
#define MKEY_NUM_6         0x01000000
#define MKEY_NUM_7         0x02000000
#define MKEY_NUM_8         0x04000000
#define MKEY_NUM_9         0x08000000

#define MKEY_FN_4          0x10000000

static const uint32_t btn_arr[] = {
  MKEY_LEFT_CTRL,
  MKEY_LEFT_WIN,
  MKEY_LEFT_SHIFT,
  MKEY_LEFT_ALT,
  MKEY_ENTER,

  MKEY_UP_ARROW,
  MKEY_DOWN_ARROW,
  MKEY_LEFT_ARROW,
  MKEY_RIGHT_ARROW,

  MKEY_BACKSPACE,
  MKEY_TAB,

  MKEY_CH_R,
  MKEY_CH_A,
  MKEY_CH_C,

  MKEY_ESC,
  MKEY_CAPS_LOCK,
  MKEY_PRINT_SCREEN,
  MKEY_FN,

  MKEY_NUM_0,
  MKEY_NUM_1,
  MKEY_NUM_2,
  MKEY_NUM_3,
  MKEY_NUM_4,
  MKEY_NUM_5,
  MKEY_NUM_6,
  MKEY_NUM_7,
  MKEY_NUM_8,
  MKEY_NUM_9,

  MKEY_FN_4
};

static const uint8_t btn_value_arr[] = {
  0x80,
  0x83,
  0x81,
  0x82,
  0xB0,

  0xDA,
  0xD9,
  0xD8,
  0xD7,

  0xB2,
  0xB3,
  
  'r',
  'a',
  'c',

  KEY_ESC,
  KEY_CAPS_LOCK,
  KEY_PRINT_SCREEN,
  KEY_INSERT,

  '0',
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9',

  KEY_F4
};

static const int BTN_N = sizeof(btn_value_arr) / sizeof(*btn_value_arr);

#define CHECK_MASK(original, n, mask) ((original) & (1 << (n))) == (mask)

#define D500 \
  delay(500);

#define DL(time) \
  delay(time);

#define RELEASE(BTN) \
  Keyboard.release(BTN);

#define RELEASE_ALL() \
  Keyboard.releaseAll();

// #define PRESS(BTN) \
//   Keyboard.press(BTN);

// (int i = BTN_N-1; i >= 0; i--)
#define PRESS(BTNS) \
  for (int i = 0; i < BTN_N; i++) { \
    if (CHECK_MASK(BTNS, i, btn_arr[i])) { \
      Keyboard.press(btn_value_arr[i]); \
    } \
  }

#define ENTER \
  PRESS(KEY_RETURN); \
  RELEASE(KEY_RETURN);

#define PRINT(str) \
  Keyboard.print(str);

#define PRINT_LN(str) \
  Keyboard.println(str);

#define PRESS_DL(BTN, dl) \
  PRESS(BTN) \
  DL(dl) \
  RELEASE(BTN)


#define OPEN_CMD \
  Keyboard.press(KEY_LEFT_GUI); \
  Keyboard.press('r'); \
  D500 \
  Keyboard.releaseAll(); \
  D500 \
  Keyboard.println("cmd");


#define OPEN_CMD_AS_ADMIN \
  Keyboard.press(KEY_LEFT_GUI); \
  Keyboard.press('r'); \
  DL(300) \
  Keyboard.releaseAll(); \
  D500 \
  Keyboard.print("cmd"); \
  D500 \
  PRESS(MKEY_LEFT_CTRL | MKEY_LEFT_SHIFT | MKEY_ENTER) \
  DL(200) \
  Keyboard.releaseAll(); \
  D500 \
  Keyboard.press(KEY_LEFT_ARROW); \
  D500 \
  Keyboard.release(KEY_LEFT_ARROW); \
  Keyboard.press(KEY_RETURN); \
  D500 \
  Keyboard.release(KEY_RETURN);
