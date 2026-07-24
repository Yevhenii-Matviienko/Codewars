#include <stdlib.h>
#include <string.h>

int check_opposites_directions(const char *direction_1, const char *direction_2) {
    return (strcmp(direction_1, "NORTH") == 0 && strcmp(direction_2, "SOUTH") == 0) ||
        (strcmp(direction_1, "SOUTH") == 0 && strcmp(direction_2, "NORTH") == 0) ||
        (strcmp(direction_1, "EAST") == 0 && strcmp(direction_2, "WEST") == 0) ||
        (strcmp(direction_1, "WEST") == 0 && strcmp(direction_2, "EAST") == 0);
}

const char **dirReduc(const char *const array[], int length_in, int *length_out) {
    const char **result = malloc(length_in * sizeof(*result));
    int result_size = 0;
    for (int index = 0; index < length_in; index++) {
        if (result_size > 0 && check_opposites_directions(result[result_size - 1], array[index])) {
            result_size--;
        } 
        else {
            result[result_size++] = array[index];
        }
    }
    *length_out = result_size;
    return result;
}