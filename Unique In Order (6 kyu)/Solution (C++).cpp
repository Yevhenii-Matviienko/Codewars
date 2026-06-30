#include <string>
#include <vector>

template <typename T> 
std::vector<T> uniqueInOrder(const std::vector<T>& iterable) {
    std::vector<T> result;
    for (const T& array_element : iterable) {
        if (result.empty() || array_element != result.back()) {
            result.push_back(array_element);
        }
    }
    return result;
}

std::vector<char> uniqueInOrder(const std::string& iterable) {
    std::vector<char> result;
    for (char string_char : iterable) {
        if (result.empty() || string_char != result.back()) {
            result.push_back(string_char);
        }
    }
    return result;
}