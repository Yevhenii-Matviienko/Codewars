#include <vector>

typedef unsigned long long ull;

class ProdFib {
    public:
        static std::vector<ull> productFib(ull prod) {
            ull number_1 = 0;
            ull number_2 = 1;
            while (number_1 * number_2 < prod)
            {
                ull number_3 = number_1 + number_2;
                number_1 = number_2;
                number_2 = number_3;
            }
            return {number_1, number_2, number_1 * number_2 == prod};
        }
};