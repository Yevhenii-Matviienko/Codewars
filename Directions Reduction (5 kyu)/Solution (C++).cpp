#include <string>
#include <vector>
#include <map>

class DirReduction
{
    public:
        static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
        {
            std::map<std::string, std::string> opposites_directions = {
                {"NORTH", "SOUTH"},
                {"SOUTH", "NORTH"},
                {"EAST", "WEST"},
                {"WEST", "EAST"}
            };
            std::vector<std::string> result;
            for (const std::string &direction : arr)
            {
                if (!result.empty() && opposites_directions[direction] == result.back())
                {
                    result.pop_back();
                }
                else
                {
                    result.push_back(direction);
                }
            }
            return result;
        }
};