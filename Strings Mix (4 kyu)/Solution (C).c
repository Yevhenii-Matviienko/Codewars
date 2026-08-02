#include <stdlib.h>
#include <string.h>

static int compare_strings(const void *pointer_string_1, const void *pointer_string_2) {
    const char *string_1 = *(const char **)pointer_string_1;
    const char *string_2 = *(const char **)pointer_string_2;
    int length_string_1 = strlen(string_1);
    int length_string_2 = strlen(string_2);
    if (length_string_1 != length_string_2) {
        return length_string_2 - length_string_1;
    }
    return strcmp(string_1, string_2);
}

char *mix(const char *s1, const char *s2) {
    int count_chars_string_1[26] = {0};
    int count_chars_string_2[26] = {0};
    for (int index_1 = 0; s1[index_1]; index_1++) {
        if (s1[index_1] >= 'a' && s1[index_1] <= 'z') {
            count_chars_string_1[s1[index_1] - 'a']++;
        } 
    }
    for (int index_2 = 0; s2[index_2]; index_2++) {
        if (s2[index_2] >= 'a' && s2[index_2] <= 'z') {
            count_chars_string_2[s2[index_2] - 'a']++;
        } 
    }
    char *result_parts[26];
    int result_parts_count = 0;
    int result_size = 1;
    for (int index_3 = 0; index_3 < 26; index_3++) {
        int max_number_char = count_chars_string_1[index_3] > count_chars_string_2[index_3] ? count_chars_string_1[index_3] : count_chars_string_2[index_3];
        if (max_number_char <= 1) {
            continue;
        }
        result_parts[result_parts_count] = malloc(max_number_char + 3);
        if (count_chars_string_1[index_3] > count_chars_string_2[index_3]) {
            result_parts[result_parts_count][0] = '1';
        }  
        else if (count_chars_string_2[index_3] > count_chars_string_1[index_3]) {
            result_parts[result_parts_count][0] = '2';
        }
        else {
            result_parts[result_parts_count][0] = '=';
        }
        result_parts[result_parts_count][1] = ':';
        for (int index_4 = 0; index_4 < max_number_char; index_4++) {
            result_parts[result_parts_count][index_4 + 2] = 'a' + index_3;
        }
        result_parts[result_parts_count][max_number_char + 2] = '\0';
        result_size += max_number_char + 3;
        result_parts_count++;
    }
    qsort(result_parts, result_parts_count, sizeof(char *), compare_strings);
    char *result = calloc(result_size, 1);
    for (int index_5 = 0; index_5 < result_parts_count; index_5++) {
        if (index_5 > 0) {
            strcat(result, "/");
        }
        strcat(result, result_parts[index_5]);
        free(result_parts[index_5]);
    }
    return result;
}