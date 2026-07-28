#include <stdlib.h>
#include <string.h>

const char *const morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  
const char *const ascii[55] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@", "SOS"};

char *decode_morse(const char *morse_code) {
    char *result = calloc(strlen(morse_code) + 1, 1);
    char *position = result;
    char letter_morse_code[10];
    while (*morse_code == ' ') {
        morse_code++;
    }
    while (*morse_code) {
        int letter_morse_code_length = 0;
        int spaces_count = 0;
        int index;
        while (*morse_code && *morse_code != ' ') {
            letter_morse_code[letter_morse_code_length++] = *morse_code++;
        }
        letter_morse_code[letter_morse_code_length] = '\0';
        for (index = 0; index < 55; index++) {
            if (strcmp(letter_morse_code, morse[index]) == 0) {
                break;
            }
        }
        strcpy(position, ascii[index]);
        position += strlen(ascii[index]);
        while (*morse_code == ' ') {
            morse_code++;
            spaces_count++;
        }
        if (*morse_code && spaces_count >= 3) {
            *position++ = ' ';
        }
    }
    return result;
}