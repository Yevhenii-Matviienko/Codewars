#include <string>
#include <algorithm>

using namespace std;

string sum_strings(const string &a, const string &b) {
    int index_1 = static_cast<int>(a.size()) - 1;
    int index_2 = static_cast<int>(b.size()) - 1;
    int carry = 0;
    string result;
    while (index_1 >= 0 || index_2 >= 0 || carry) {
        int digit_string_1 = index_1 >= 0 ? a[index_1] - '0' : 0;
        int digit_string_2 = index_2 >= 0 ? b[index_2] - '0' : 0;
        int total_digits_sum = digit_string_1 + digit_string_2 + carry;
        result.push_back(static_cast<char>('0' + total_digits_sum % 10));
        carry = total_digits_sum / 10;
        --index_1;
        --index_2;
    }
    reverse(result.begin(), result.end());
    size_t start_position = result.find_first_not_of('0');
    if (start_position == string::npos) {
        return "0";
    }
    return result.substr(start_position);
}