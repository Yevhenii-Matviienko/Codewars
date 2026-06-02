def sum_of_intervals(intervals):
    intervals.sort()
    total_length = 0
    start, end = intervals[0]
    for current_start, current_end in intervals[1:]:
        if current_start <= end:
            end = max(end, current_end)
        else:
            total_length += end - start
            start, end = current_start, current_end
    total_length += end - start
    return total_length