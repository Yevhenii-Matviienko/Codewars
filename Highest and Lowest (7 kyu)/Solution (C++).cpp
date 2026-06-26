#include <string>
#include <vector>
#include <algorithm>

std::string highAndLow(const std::string& numbers) {
    std::vector<int> numbers_int;
    std::string current_number = "";
    for (char number : numbers) {
        if (number == ' ') {
            numbers_int.push_back(std::stoi(current_number));
            current_number = "";
        } else {
            current_number += number;
        }
    }
    numbers_int.push_back(std::stoi(current_number));
    int largest_number = *std::max_element(numbers_int.begin(), numbers_int.end());
    int smallest_number = *std::min_element(numbers_int.begin(), numbers_int.end());
    return std::to_string(largest_number) + " " + std::to_string(smallest_number);
}