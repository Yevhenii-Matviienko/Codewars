#include <string>
#include <cmath>

class DigPow {
    public:
        static int digPow(int n, int p)
        {
            int sum = 0;
            for (char digit : std::to_string(n))
            {
                sum += std::pow(digit - '0', p);
                p++;
            }
            return sum % n == 0 ? sum / n : -1;
        }
};