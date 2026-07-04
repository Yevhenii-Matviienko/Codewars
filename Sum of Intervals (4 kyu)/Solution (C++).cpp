#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int sum_intervals(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end());
    int start = intervals[0].first;
    int end = intervals[0].second;
    int total_length = 0;
    for (int index = 1; index < intervals.size(); index++) {
        int current_start = intervals[index].first;
        int current_end = intervals[index].second;
        if (current_start <= end) {
            end = max(end, current_end);
        } else {
            total_length += end - start;
            start = current_start;
            end = current_end;
        }
    }
    total_length += end - start;
    return total_length;
}