#include <array>
#include <algorithm>

int score(const std::array<unsigned, 5>& dice)
{
    int total_score = 0;
    for (unsigned n = 1; n <= 6; n++)
    {
        int n_count = std::count(dice.begin(), dice.end(), n);
        if (n_count >= 3)
        {
            total_score += (n == 1) ? 1000 : n * 100;
            n_count -= 3;
        }
        if (n == 1)
        {
            total_score += n_count * 100;
        }
        if (n == 5)
        {
            total_score += n_count * 50;
        }
    }
    return total_score;
}