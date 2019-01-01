// Given a collection of distinct integers, return all possible permutations.

// Example:
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <stdio.h>
#include <stdlib.h>

void printarr(int* arr, int len) {
    printf("{ ");
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d }\n", arr[len - 1]);
}

void set_p(int* nums, int n_len, int n_i, int* flag, int** arrs, int* p_i) {
    if (n_i == n_len) {
        arrs[*p_i] = (int*)malloc(sizeof(int) * n_len);
        for (int i = 0; i < n_len; i++) {
            arrs[*p_i][flag[i]] = nums[i];
        }
        (*p_i)++;
    }
    for (int i = 0; i < n_len; i++) {
        if (flag[i] == -1) {
            flag[i] = n_i;
            set_p(nums, n_len, n_i + 1, flag, arrs, p_i);
            flag[i] = -1;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int size = 1;
    for (int i = 1; i <= numsSize; i++) size *= i;
    int** arrs = (int**)malloc(sizeof(int*) * size);
    int* flag = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) flag[i] = -1;
    *returnSize = 0;
    set_p(nums, numsSize, 0, flag, arrs, returnSize);
    return arrs;
}

int main(int argc, char const* argv[]) {
    int nums[3] = {4, 5, 6};
    int returnSize;
    int** arr = permute(nums, 3, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printarr(arr[i], 3);
    }
    return 0;
}
