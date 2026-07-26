int score(const int dice[5]) {
    int dice_values_count[6] = {0};
    int result = 0;
    for (int die = 0; die < 5; die++) {
        dice_values_count[dice[die] - 1]++;
    }
    for (int die_value = 1; die_value <= 6; die_value++) {
        if (dice_values_count[die_value - 1] >= 3) {
            if (die_value == 1) {
                result += 1000;
            } 
            else {
                result += die_value * 100;
            }
            dice_values_count[die_value - 1] -= 3;
        }
        if (die_value == 1) {
            result += dice_values_count[die_value - 1] * 100;
        }
        if (die_value == 5) {
            result += dice_values_count[die_value - 1] * 50;
        }
    }
    return result;
}