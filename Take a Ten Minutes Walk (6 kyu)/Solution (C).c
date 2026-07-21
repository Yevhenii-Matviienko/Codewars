#include <stdbool.h>
#include <string.h>

bool isValidWalk(const char *walk) {
    int n = 0, e = 0, s = 0, w = 0;
    if (strlen(walk) != 10) {
        return false;
    }
    for (int index = 0; walk[index] != '\0'; index++) {
        if (walk[index] == 'n') {
            n++;
        }
        if (walk[index] == 'e') {
            e++;
        }
        if (walk[index] == 's') {
            s++;
        }
        if (walk[index] == 'w') {
            w++;
        }
    }
    return (n == s) && (e == w);
}