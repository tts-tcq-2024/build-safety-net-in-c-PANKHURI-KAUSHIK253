#ifndef SOUNDEX_H
#define SOUNDEX_H
#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Get the code from pattern
char getSoundexCodeFromPattern(char c, const char *soundexPattern)
{
    c = toUpper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexPattern[c - 'A'];
    }
    return '0'; // For any character outside A-Z
}

char getSoundexCode(char c) {
    // Update the Pattern with A to Z characters by numbers 
    static const char soundexPattern[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', // A-H
        '0', '2', '2', '4', '5', '5', '0', '1', // I-P
        '2', '6', '2', '3', '0', '1', '0', '2', // Q-X
        '0', '2'                                // Y-Z
    };
    
    return getSoundexCodeFromPattern(c, soundexPattern);
    
}

void verifyCode(char code, char *soundex, int *sIndex)
{
    if (code != '0' && code != soundex[*sIndex - 1]) {
            soundex[(*sIndex)++] = code;
    }
}

void processSoundex(const char *name, char *soundex, int *sIndex)
{
    int len = strlen(name);
    for (int i = 1; i < len && *sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        processCode(code, soundex, sIndex);
    }
}

void padWithZero(char *soundex, int sIndex)
{
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    processSoundex(name, soundex, &sIndex);
    
    padWithZero(soundex, sIndex);
}

#endif // SOUNDEX_H

    padsWithZero(soundex, sIndex);
}

#endif // SOUNDEX_H
