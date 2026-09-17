def longestSlideDown(pyramid: List[List[Int]]): Int = {
    pyramid.reduceRight { 
        (current_row, next_row) => current_row.zip(next_row.zip(next_row.tail)).map {
            case (parent_value, (left_child_value, right_child_value)) => parent_value + math.max(left_child_value, right_child_value)
        }
    }.head
}