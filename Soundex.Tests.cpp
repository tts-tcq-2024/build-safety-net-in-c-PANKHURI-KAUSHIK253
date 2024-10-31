#include <string>
#include <cctype>
#include <unordered_map>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexCodes {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'},
        {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    
    c = toupper(c);
    auto it = soundexCodes.find(c);
    if (it != soundexCodes.end()) {
        return it->second;
    } else {
        return '0'; // For A, E, I, O, U, H, W, Y and other characters
    }
}

std::string initializeSoundex(const std::string& name, char firstChar) {
    std::string soundex(1, toupper(name[0]));
    char secondex = getSoundexCode(name[1]);
    if (secondex != '0') {
        soundex += secondex;
    }
    return soundex;
}

