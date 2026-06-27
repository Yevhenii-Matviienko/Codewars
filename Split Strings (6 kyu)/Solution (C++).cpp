#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> result;
    for (int index = 0; index < s.length(); index += 2)
    {
        if (index + 1 < s.length())
            result.push_back(s.substr(index, 2));
        else
            result.push_back(s.substr(index, 1) + "_");
    }
    return result;
}