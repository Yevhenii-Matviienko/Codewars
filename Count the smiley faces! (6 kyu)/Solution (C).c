#include <stddef.h>

size_t count_smileys(size_t length, const char *const array[length]) {
    size_t smileys_count = 0;
    for (size_t index = 0; index < length; index++) {
        const char *smiley = array[index];
        if ((smiley[0] == ':' || smiley[0] == ';') &&
            ((smiley[1] == ')' || smiley[1] == 'D') && smiley[2] == '\0' ||
            (smiley[1] == '-' || smiley[1] == '~') &&
            (smiley[2] == ')' || smiley[2] == 'D') && smiley[3] == '\0')) {
            smileys_count++;
        }
    }
    return smileys_count;
}