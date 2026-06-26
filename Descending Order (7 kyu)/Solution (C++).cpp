#include <cinttypes>
#include <string>
#include <algorithm>

uint64_t descendingOrder(uint64_t a)
{
    std::string digits = std::to_string(a);
    std::sort(digits.begin(), digits.end(), std::greater<char>());
    return std::stoull(digits);
}