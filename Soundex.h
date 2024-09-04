#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <cctype>

char getSoundexCode(char c) 
{
    static const std::string codes = "01230120022455012623010202";
    return std::isalpha(c) ? codes[std::toupper(c) - 'A'] : '0';
}

std::string generateSoundex(const std::string &name) {
    std::string soundex(1, std::toupper(name[0]));
    
    for (std::size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex.back()) {
            soundex += code;
        }
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}

#endif // SOUNDEX_H

