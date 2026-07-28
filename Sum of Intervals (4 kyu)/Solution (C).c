#include <stdlib.h>

struct interval {
    int first;
    int second;
};

static int compare_intervals(const void *first_value, const void *second_value) {
    const struct interval *first_interval = first_value;
    const struct interval *second_interval = second_value;
    if (first_interval->first < second_interval->first) {
        return -1;
    }
    if (first_interval->first > second_interval->first) {
        return 1;
    }
    return 0;
}

int sum_intervals(const struct interval *v, size_t n) {
    if (n == 0) {
        return 0;
    }
    struct interval *sorted_intervals = malloc(n * sizeof(struct interval));
    for (size_t index = 0; index < n; index++) {
        sorted_intervals[index] = v[index];
    }
    qsort(sorted_intervals, n, sizeof(struct interval), compare_intervals);
    int current_start = sorted_intervals[0].first;
    int current_end = sorted_intervals[0].second;
    int total_length = 0;
    for (size_t index = 1; index < n; index++) {
        int next_start = sorted_intervals[index].first;
        int next_end = sorted_intervals[index].second;
        if (next_start <= current_end) {
            if (next_end > current_end) {
                current_end = next_end;
            }
        }
        else {
            total_length += current_end - current_start;
            current_start = next_start;
            current_end = next_end;
        }
    }
    total_length += current_end - current_start;
    free(sorted_intervals);
    return total_length;
}
