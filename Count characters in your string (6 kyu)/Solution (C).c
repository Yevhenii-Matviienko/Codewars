#define COUNTS_SIZE 128

void count(const char *string, unsigned counts[COUNTS_SIZE]) {
    for (unsigned index = 0; index < COUNTS_SIZE; index++) {
        counts[index] = 0;
    }
    for (; *string; string++) {
        counts[(unsigned char)*string]++;
    }
}