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