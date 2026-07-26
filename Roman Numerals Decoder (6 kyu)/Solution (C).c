unsigned decode_roman(const char *roman) {
    const char *symbols = "IVXLCDM";
    const unsigned numbers[] = {1, 5, 10, 50, 100, 500, 1000};
    unsigned current_index;
    unsigned next_index;
    unsigned result = 0;
    for (; *roman; roman++) {
        for (current_index = 0; symbols[current_index] != *roman; current_index++) { }
        for (next_index = 0; roman[1] && symbols[next_index] != roman[1]; next_index++) { }
        if (roman[1] && numbers[current_index] < numbers[next_index]) {
            result -= numbers[current_index];
        } 
        else {
            result += numbers[current_index];
        }
    }
    return result;
}