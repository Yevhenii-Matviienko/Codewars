char *binary_add(unsigned a, unsigned b, char *binary) {
    unsigned long long sum = (unsigned long long)a + b;
    char temporary_array[65];
    if (sum == 0) {
        binary[0] = '0';
        binary[1] = '\0';
        return binary;
    }
    int index_0 = 0;
    while (sum > 0) {
        temporary_array[index_0++] = (sum % 2) + '0';
        sum /= 2;
    }
    for (int index_1 = 0; index_1 < index_0; index_1++) {
        binary[index_1] = temporary_array[index_0 - 1 - index_1];
    }
    binary[index_0] = '\0';
    return binary;
}