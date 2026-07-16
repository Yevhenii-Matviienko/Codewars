function fibonacci(max) {
    let number_1 = 0;
    let number_2 = 1;
    let total_sum = 0;
    while (number_1 < max) {
        if (number_1 % 2 === 0) {
            total_sum += number_1;
        }
        [number_1, number_2] = [number_2, number_1 + number_2];
    }
    return total_sum;
}