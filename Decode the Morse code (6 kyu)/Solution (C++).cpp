#include <string>
#include <sstream>

std::string decodeMorse(const std::string& morseCode) {
    std::string morse_code = morseCode;
    morse_code.erase(0, morse_code.find_first_not_of(' '));
    morse_code.erase(morse_code.find_last_not_of(' ') + 1);
    int word_start_position = 0;
    int gap_position;
    std::string result;
    while (true) {
        gap_position = morse_code.find("   ", word_start_position);
        std::string word = morse_code.substr(word_start_position, gap_position - word_start_position);
        std::stringstream word_string_stream(word);
        std::string letter;
        while (word_string_stream >> letter) {
            result += MORSE_CODE[letter];
        }
        if (gap_position == std::string::npos) {
            break;
        }
        result += ' ';
        word_start_position = gap_position + 3;
    }
    return result;
}