#include <string>
#include <map>

std::map<char, unsigned> count(const std::string& string) {
    std::map<char, unsigned> result;
    for (char string_char : string) {
        result[string_char]++;
    }
    return result;
}