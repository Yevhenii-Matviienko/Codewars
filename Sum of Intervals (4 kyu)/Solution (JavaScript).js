function sumIntervals(intervals) {
  intervals.sort((a, b) => a[0] - b[0]);
  let total_length = 0;
  let [start, end] = intervals[0];
  for (let index = 1; index < intervals.length; index++) {
    let [current_start, current_end] = intervals[index];
    if (current_start <= end) {
      end = Math.max(end, current_end);
    } else {
      total_length += end - start;
      start = current_start;
      end = current_end;
    }
  }
  total_length += end - start;
  return total_length;
}