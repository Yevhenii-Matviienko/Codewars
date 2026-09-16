def sumOfIntervals(intervals: List[(Int, Int)]): Int = {
    val sorted_intervals = intervals.sortBy(_._1)
    var (start, end) = sorted_intervals.head
    var total_length = 0
    for ((current_start, current_end) <- sorted_intervals.tail) {
        if (current_start <= end) {
            end = math.max(end, current_end)
        } 
        else {
            total_length += end - start
            start = current_start
            end = current_end
        }
    }
    total_length += end - start
    return total_length
}