#include "tools.h"

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
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

void print_int_array(int* array, int length) {
    std::cout << "{" << array[0];
    for (int i = 1; i < length; i++) {
        std::cout << ", " << array[i];
    }
    std::cout << "}\n";
}

void print_int_arrays(int** arrays, int row, int col) {
    for (int i = 0; i < row; i++) {
        print_int_array(arrays[i], col);
    }
}

void insert_sort(int* nums, int length) {
    int i, j;
    for (i = 1; i < length; i++) {
        int temp = nums[i];
        for (j = i; j > 0 && temp < nums[j - 1]; j--) {
            nums[j] = nums[j - 1];
        }
        nums[j] = temp;
    }
}