#include "s21_string.h"

size_t s21_strlen(const char *str) {
    size_t len = 0;
    for (; str[len] != '\0'; len++);
    return len;
}

int s21_strcmp(const char *str1, const char *str2) {
    int r = 1;
    size_t len1 = s21_strlen(str1);
    if (len1 != s21_strlen(str2)) {
        r = 0;
    }
    for (size_t i = 0; i < len1 && r; i++) {
        if (str1[i] != str2[i]) {
            r = 0;
        }
    }
    return r;
}

char *s21_strcpy(char *dest, const char *src) {
    int i = 0;
    while (1) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
        i++;
    }
    return dest;
}
char *s21_strcat(char *dest, const char *src) {
    size_t len1 = s21_strlen(dest);
    int j = 0;
    for (size_t i = len1; 1; i++) {
        dest[i] = src[j];
        j++;
        if (src[j] == '\0') {
            break;
        }
    }
    return dest;
}

char *s21_strchr(char *string, int symbol) {
    char val = (char)symbol;
    int i = 0;
    char *result = NULL;
    int b = 1;
    while (string[i] != '\0' && b) {
        if (string[i] == val) {
            result = string + i;
            b = 0;
        }
        i++;
    }
    if (symbol == '\0') {
        result = string + i;
    }
    return result;
}

char *s21_strstr(char *str1, char *str2) {
    char *result = NULL;
    int i = 0;
    size_t len2 = s21_strlen(str2);
    int b = 1;
    while (str1[i] != '\0' && b) {
        int cb = 1;
        for (size_t j = 0; j < len2 && cb; j++) {
            if (str1[j + i] == '\0') {
                b = 0;
                cb = 0;
            } else if (str1[j + i] != str2[j]) {
                cb = 0;
            }
        }
        if (cb) {
            result = str1 + i;
            b = 0;
        }
        i++;
    }
    return result;
}
