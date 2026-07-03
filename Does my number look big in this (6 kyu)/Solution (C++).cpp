#include <string>
#include <cmath>

bool narcissistic(int value) {
    int sum = 0;
    std::string digits = std::to_string(value);
    int power = digits.length();
    for (char digit : digits) {
        int number = digit - '0';
        sum += std::pow(number, power);
    }
    return sum == value;
}