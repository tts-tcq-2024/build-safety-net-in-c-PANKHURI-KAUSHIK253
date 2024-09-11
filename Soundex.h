#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Helper function to get the Soundex code for a character
char getSoundexCode(char c) {
    switch (toupper(c)) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

// Simplified function to generate the Soundex code
void generateSoundex(const char *name, char *soundex) {
    // First letter is always uppercase in Soundex
    soundex[0] = toupper(name[0]);

    int sIndex = 1; // Tracks the current position in the Soundex code

    // Loop through the rest of the characters in the name
    for (int i = 1; name[i] != '\0' && sIndex < 4; ++i) {
        char code = getSoundexCode(name[i]);

        // Add the code if it's not '0' and it's not the same as the previous code
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    // Pad the Soundex code with '0' if necessary to make it 4 characters long
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    // Null-terminate the string
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
