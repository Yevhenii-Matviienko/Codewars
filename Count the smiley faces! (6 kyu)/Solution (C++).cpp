#include <string>
#include <vector>
#include <regex>

int countSmileys(std::vector<std::string> arr)
{
    std::regex pattern("[:;][-~]?[)D]");
    int smileys_counter = 0;
    for (const std::string& smiley : arr)
    {
        if (std::regex_match(smiley, pattern))
        {
            smileys_counter++;
        }
    }
    return smileys_counter;
}