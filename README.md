# EasyBadUsb
simple header only lib written in C++ to make BadUsb scripting easier (Arduino IDE)


### first, include cmd.hpp in your sketch file
```cpp
#include "cmd.hpp"
```

### then between BEGIN ... END we write our commands
```cpp
BEGIN

//
// commands
//

END
```


### The PRESS function is used to press special keys and simultaneously press several keys on the keyboard
```cpp
PRESS(MKEY_LEFT_CTRL | MKEY_LEFT_SHIFT | MKEY_ENTER)

PRESS(MKEY_LEFT_ARROW)
```

#### buttons definitions
```cpp
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
```

### delay functions
```cpp
DL(milliseconds) // milliseconds in arguments
```

### release functions
```cpp
RELEASE(BTN) // release button or bit mask
RELEASE_ALL() // release all buttons
```

### print functions
```cpp
PRINT(str) // enter string
PRINT_LN(str) // enter string with new line
```

### implementation of opening cmd
```
OPEN_CMD() // open cmd
OPEN_CMD_AS_ADMIN() // open cmd as admin user
```



### example
```cpp
#include "cmd.hpp"

BEGIN

  PRESS(MKEY_LEFT_WIN | MKEY_CH_R)
  DL(300)
  RELEASE_ALL()

  PRINT("cmd")
  DL(500)

  PRESS(MKEY_LEFT_CTRL | MKEY_LEFT_SHIFT | MKEY_ENTER)
  DL(300)
  RELEASE_ALL()

  DL(500)

  PRESS(MKEY_LEFT_ARROW)
  
  DL(500)

  PRESS(MKEY_ENTER)

  DL(500)
  RELEASE_ALL()

  DL(500)
  PRINT_LN("echo Hello World as ADMIN!")

END
```
