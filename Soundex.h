#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Helper function to get the Soundex code for a character
char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

// Function to generate Soundex code using map
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    
    // Set the first letter of the soundex as the uppercase version of the first character
    soundex[0] = toupper(name[0]);

    // Use map to apply getSoundexCode to all characters in name and store them in a temporary array
    char tempSoundex[len];
    tempSoundex[0] = soundex[0];
    std::transform(name + 1, name + len, tempSoundex + 1, getSoundexCode);
    
    // Remove duplicates and '0' from tempSoundex while populating soundex
    int sIndex = 1;
    for (int i = 1; i < len && sIndex < 4; i++) {
        if (tempSoundex[i] != '0' && tempSoundex[i] != tempSoundex[i - 1]) {
            soundex[sIndex++] = tempSoundex[i];
        }
    }
    
    // Pad with '0' if necessary
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
