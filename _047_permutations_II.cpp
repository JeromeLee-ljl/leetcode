// Given a collection of numbers that might contain duplicates, return all
// possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "tools.h"
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void permute(int* nums, int numsSize, int* returnSize, int from, bool onlyCountSize, int** permutations) {
    if (from == numsSize) {
        (*returnSize)++;
        if (!onlyCountSize) {
            int* permutation = (int*)malloc(sizeof(int) * numsSize);
            for (int i = 0; i < numsSize; i++) {
                permutation[i] = nums[i];
            }
        }
        return;
    }
    permute(nums, numsSize, returnSize, from + 1, onlyCountSize, permutations);
    for (int i = from + 1; i < numsSize; i++) {
        if (nums[i] == nums[from]) continue;
        swap(nums, from, i);
        permute(nums, numsSize, returnSize, from + 1, onlyCountSize,
                permutations);
        swap(nums, from, i);
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    permute(nums, numsSize, returnSize, 0, true, nullptr);
    int** permutations = (int**)malloc(sizeof(int*) * *returnSize);
    permute(nums, numsSize, returnSize, 0, false, permutations);
    return permutations;
}

int main(int argc, char const* argv[]) {
    int nums[3] = {1, 1, 2};
    int returnSize;
    int** arrays = permuteUnique(nums, 3, &returnSize);
    printf("returnSize: %d\n",returnSize);
    print_int_arrays(arrays, returnSize, 3);
    return 0;
}
