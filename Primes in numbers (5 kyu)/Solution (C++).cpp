#include <string>

using namespace std;

class PrimeDecomp {
    public:
        static string factors(int lst) {
            string result = "";
            int divisor = 2;
            while (divisor * divisor <= lst) {
                int count_divisions = 0;
                while (lst % divisor == 0) {
                    count_divisions++;
                    lst /= divisor;
                }
                if (count_divisions == 1) {
                    result += "(" + to_string(divisor) + ")";
                } 
                else if (count_divisions > 1) {
                    result += "(" + to_string(divisor) + "**" + to_string(count_divisions) + ")";
                }
                divisor++;
            }
            if (lst > 1) {
                result += "(" + to_string(lst) + ")";
            }
            return result;
        }
};