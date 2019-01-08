#include "tools.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(char* a, char* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool array_equ(int* a, int* b, int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int factorial(int n) {
    int value = 1;
    for (int i = 1; i <= n; i++) {
        value *= i;
    }
    return value;
}

void print_array(int* array, int length) {
    printf("{%d", array[0]);
    for (int i = 1; i < length; i++) {
        printf(", %d", array[i]);
    }
    printf("}\n");
}
void print_array(char** array, int length) {
    printf("{\"%s\"", array[0]);
    for (int i = 1; i < length; i++) {
        printf(", \"%s\"", array[i]);
    }
    printf("}\n");
}

void print_arrays(int** arrays, int row, int col) {
    printf("{\n");
    for (int i = 0; i < row; i++) {
        printf("  ");
        print_array(arrays[i], col);
    }
    printf("}\n");
}
void print_arrays(char*** arrays, int row, int col) {
    printf("{\n");
    for (int i = 0; i < row; i++) {
        printf("  ");
        print_array(arrays[i], col);
    }
    printf("}\n");
}

int compare_str(char* str1, char* str2) {
    int i = 0;
    for (; str1[i] == str2[i]; i++) {
        if (str1[i] == '\0') return 0;
    }
    if (str1[i] > str2[i]) {
        return 1;
    } 
    return -1;
}

void select_sort(int* array, int begin, int end) {
    int *i, *j, *min,* array_end = array + end;
    for (i = array + begin; i < array_end; i++) {
        for (j = i + 1, min = i; j < array_end; j++) {
            if (*j < *min) min = j;
        }
        swap(i, min);
    }
}
void select_sort(char* array, int begin, int end) {
    char *i, *j, *min,* array_end = array + end;
    for (i = array + begin; i < array_end; i++) {
        for (j = i + 1, min = i; j < array_end; j++) {
            if (*j < *min) min = j;
        }
        swap(i, min);
    }
}


