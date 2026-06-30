#include <vector>

int FindOutlier(std::vector<int> arr)
{
    std::vector<int> evens_numbers;
    std::vector<int> odds_numbers;
    for (int number : arr)
    {
        if (number % 2 == 0)
        {
            evens_numbers.push_back(number);
        }
        else
        {
            odds_numbers.push_back(number);
        }
    }
    return evens_numbers.size() == 1 ? evens_numbers[0] : odds_numbers[0];
}