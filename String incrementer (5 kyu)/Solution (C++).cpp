#include <string>
#include <cctype>

std::string incrementString(const std::string &str)
{
    int index = str.size() - 1;
    while (index >= 0 && std::isdigit(str[index]))
    {
        index--;
    }
    std::string text = str.substr(0, index + 1);
    std::string number = str.substr(index + 1);
    if (number.empty())
    {
        return str + "1";
    }
    int carry = 1;
    for (int index = number.size() - 1; index >= 0; index--)
    {
        if (number[index] == '9')
        {
            number[index] = '0';
        }
        else
        {
            number[index]++;
            carry = 0;
            break;
        }
    }
    if (carry)
    {
        number.insert(number.begin(), '1');
    }
    return text + number;
}