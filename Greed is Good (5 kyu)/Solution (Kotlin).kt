package solution

fun score(dice: IntArray): Int {
    var total_score = 0
    for (die_value in 1..6) {
        var die_value_count = dice.count { die -> die == die_value }
        if (die_value_count >= 3) {
            total_score += if (die_value == 1) 1000 else die_value * 100
            die_value_count -= 3
        }
        if (die_value == 1) {
            total_score += die_value_count * 100
        }
        if (die_value == 5) {
            total_score += die_value_count * 50
        }
    }
    return total_score
}