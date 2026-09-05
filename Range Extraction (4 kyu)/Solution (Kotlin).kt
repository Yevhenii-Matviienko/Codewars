fun rangeExtraction(arr: IntArray): String {
    var range_start_index = 0
    val result = mutableListOf<String>()
    for (range_end_index in arr.indices) {
        if (range_end_index == arr.lastIndex || arr[range_end_index + 1] != arr[range_end_index] + 1) {
            result += when (range_end_index - range_start_index) {
                0 -> "${arr[range_start_index]}"
                1 -> "${arr[range_start_index]},${arr[range_end_index]}"
                else -> "${arr[range_start_index]}-${arr[range_end_index]}"
            }
            range_start_index = range_end_index + 1
        }
    }
    return result.joinToString(",")
}