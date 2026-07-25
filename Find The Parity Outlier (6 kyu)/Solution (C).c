#include <stddef.h>

int find_outlier(const int values[], size_t count) {
    int even_numbers_count = 0;
    int odd_numbers_count = 0;
    int last_even_number = 0;
    int last_odd_number = 0;
    for (size_t index = 0; index < count; index++) {
        if (values[index] % 2 == 0) { 
            even_numbers_count++; 
            last_even_number = values[index];
        }
        else { 
            odd_numbers_count++; 
            last_odd_number = values[index];
        }
    }
    return even_numbers_count == 1 ? last_even_number : last_odd_number;
}