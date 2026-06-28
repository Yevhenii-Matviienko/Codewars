#include <string>
#include <algorithm>

std::string duplicate_encoder(const std::string& word)
{
    std::string word_lowercase = word;
    std::string result = "";
    std::transform(word_lowercase.begin(), word_lowercase.end(), word_lowercase.begin(), ::tolower);
    for (char word_char : word_lowercase)
    {
        if (std::count(word_lowercase.begin(), word_lowercase.end(), word_char) > 1)
        {
            result += ")";
        }
        else
        {
            result += "(";
        }
    }
    return result;
}