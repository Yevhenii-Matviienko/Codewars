fun solution(start: Int, finish: Int): Int {
    val shelves_difference = finish - start
    return shelves_difference / 3 + shelves_difference % 3
}