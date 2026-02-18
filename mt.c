#include "s21_string.h"

void s21_strlen_test() {
    char test1[] = "Hello World!";
    printf("\"%s\"", test1);
    printf(" %ld ", s21_strlen(test1));
    if (s21_strlen(test1) == 12) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test2[] = "";
    printf("\"%s\"", test2);
    printf(" %ld ", s21_strlen(test2));
    if (s21_strlen(test2) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test3[] = "12345 6";
    printf("\"%s\"", test3);
    printf(" %ld ", s21_strlen(test3));
    if (s21_strlen(test3) == 7) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test4[] = "HeLlO WoRlD!";
    printf("\"%s\"", test4);
    printf(" %ld ", s21_strlen(test4));
    if (s21_strlen(test4) == 12) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test5[] = ".\n,$#@";
    printf("\"%s\"", test5);
    printf(" %ld ", s21_strlen(test5));
    if (s21_strlen(test5) == 6) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test() {
    char test11[] = "Hello World!";
    char test12[] = "Hello World!";
    printf("\"%s\" \"%s\"", test11, test12);
    printf(" %d ", s21_strcmp(test11, test12));
    if (s21_strcmp(test11, test12)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test21[] = "";
    char test22[] = "";

    printf("\"%s\" \"%s\"", test21, test22);
    printf(" %d ", s21_strcmp(test21, test22));
    if (s21_strcmp(test21, test22)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test31[] = "abc";
    char test32[] = "abcabc";

    printf("\"%s\" \"%s\"", test31, test32);
    printf(" %d ", s21_strcmp(test31, test32));
    if (s21_strcmp(test31, test32) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test41[] = "HeLlO WoRlD!";
    char test42[] = "hElLo wOrLd!";

    printf("\"%s\" \"%s\"", test41, test42);
    printf(" %d ", s21_strcmp(test41, test42));
    if (s21_strcmp(test41, test42) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test51[] = "gbfd";
    char test52[] = "";
    printf("\"%s\" \"%s\"", test51, test52);
    printf(" %d ", s21_strcmp(test51, test52));
    if (s21_strcmp(test51, test52) == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcpy_test() {
    char test11[100] = "Hello World!";
    char test12[100] = "Goodbye World!";
    printf("\"%s\" \"%s\"", test11, test12);
    s21_strcpy(test11, test12);
    printf(" %d ", s21_strcmp(test11, test12));
    if (s21_strcmp(test11, test12)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test21[10] = "";
    char test22[10] = "abc";

    printf("\"%s\" \"%s\"", test21, test22);
    s21_strcpy(test21, test22);
    printf(" %d ", s21_strcmp(test21, test22));
    if (s21_strcmp(test21, test22)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test31[10] = "abc";
    char test32[10] = "";

    printf("\"%s\" \"%s\"", test31, test32);
    s21_strcpy(test31, test32);
    printf(" %d ", s21_strcmp(test31, test32));
    if (s21_strcmp(test31, test32)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test41[20] = "HeLlO WoRlD!";
    char test42[20] = "hElLo wOrLd!";

    printf("\"%s\" \"%s\"", test41, test42);
    s21_strcpy(test41, test42);
    printf(" %d ", s21_strcmp(test41, test42));
    if (s21_strcmp(test41, test42)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcat_test() {
    char test11[100] = "Hello World!";
    char test12[100] = "Goodbye World!";
    char result1[100] = "Hello World!Goodbye World!";
    printf("\"%s\" \"%s\"", test11, test12);
    s21_strcat(test11, test12);
    printf(" \"%s\" ", test11);
    if (s21_strcmp(test11, result1)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test21[10] = "";
    char test22[10] = "abc";
    char result2[10] = "abc";

    printf("\"%s\" \"%s\"", test21, test22);
    s21_strcat(test21, test22);
    printf(" \"%s\" ", test21);
    if (s21_strcmp(test21, result2)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test31[10] = "abc";
    char test32[10] = "";
    char result3[10] = "abc";

    printf("\"%s\" \"%s\"", test31, test32);
    s21_strcat(test31, test32);
    printf(" \"%s\" ", test31);
    if (s21_strcmp(test31, result3)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test41[30] = "HeLlO WoRlD!";
    char test42[30] = "hElLo wOrLd!";
    char result4[40] = "HeLlO WoRlD!hElLo wOrLd!";

    printf("\"%s\" \"%s\"", test41, test42);
    s21_strcat(test41, test42);
    printf(" \"%s\" ", test41);
    if (s21_strcmp(test41, result4)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strchr_test() {
    char* result;
    char val;

    char test11[100] = "Hello World!";
    val = 'W';
    printf("\"%s\" \"%c\"", test11, val);
    result = s21_strchr(test11, val);
    printf(" %d ", val);
    if (result == &(test11[6])) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test21[10] = "";
    val = '\0';
    printf("\"%s\" \"%c\"", test21, val);
    result = s21_strchr(test21, val);
    printf(" %d ", val);
    if (result == &(test21[0])) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test31[10] = "abc";
    val = 'd';
    printf("\"%s\" \"%c\"", test31, val);
    result = s21_strchr(test31, val);
    printf(" %d ", val);
    if (result == NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test41[20] = "HeLlO WoRlD!";
    val = ' ';
    printf("\"%s\" \"%c\"", test41, val);
    result = s21_strchr(test41, val);
    printf(" %d ", val);
    if (result == &(test41[5])) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strstr_test() {
    char* result;

    char test11[100] = "Hello World!";
    char test12[100] = "World";
    printf("\"%s\" \"%s\"", test11, test12);
    result = s21_strstr(test11, test12);
    printf(" %p ", result);
    if (result == &(test11[6])) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test21[10] = "";
    char test22[10] = "abc";
    printf("\"%s\" \"%s\"", test21, test22);
    result = s21_strstr(test21, test12);
    printf(" %p ", result);
    if (result == NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test31[10] = "abc";
    char test32[10] = "abc";
    printf("\"%s\" \"%s\"", test31, test32);
    result = s21_strstr(test31, test32);
    printf(" %p ", result);
    if (result == &(test31[0])) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test41[20] = "HeLlO WoRlD!";
    char test42[20] = "gfdgfsdgsdf";
    printf("\"%s\" \"%s\"", test41, test42);
    result = s21_strstr(test41, test42);
    printf(" %p ", result);
    if (result == NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

int main() {
#ifdef Q6
    s21_strlen_test();
#endif
#ifdef Q7
    s21_strcmp_test();
#endif
#ifdef Q8
    s21_strcpy_test();
#endif
#ifdef Q9
    s21_strcat_test();
#endif
#ifdef Q10
    s21_strchr_test();
#endif
#ifdef Q11
    s21_strstr_test();
#endif
#ifdef Q12
    s21_strlen_test();
    s21_strcmp_test();
    s21_strcpy_test();
    s21_strcat_test();
    s21_strchr_test();
    s21_strstr_test();
#endif

    return 0;
}
