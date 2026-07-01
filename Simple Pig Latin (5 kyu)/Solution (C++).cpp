#include <string>
#include <sstream>
#include <cctype>

std::string pig_it(std::string str) {
    std::stringstream string_stream(str);
    std::string word;
    std::string result;
    while (string_stream >> word) {
        if (!result.empty()) {
            result += " ";
        }
        if (std::isalpha(word[0])) {
            result += word.substr(1) + word[0] + "ay";
        }
        else {
            result += word;
        }
    }
    return result;
}