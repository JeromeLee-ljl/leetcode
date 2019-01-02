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

#include "../include/tools.cpp"
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void permute(int* nums, int numsSize, int index, int* targets, int** permutations, int* returnSize) {
    if (index == numsSize) {
        permutations[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            permutations[*returnSize][targets[i]] = nums[i];
        }
        (*returnSize)++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (targets[i] != -1) continue;
        if (i != 0 && nums[i] == nums[i - 1] && targets[i - 1] == -1) continue;
        targets[i] = index;
        permute(nums, numsSize, index + 1, targets, permutations, returnSize);
        targets[i] = -1;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    insert_sort(nums, numsSize);
    int** permutations = (int**)malloc(sizeof(int*) * factorial(numsSize));
    int* targets = (int*)malloc(sizeof(int) * numsSize);
    // nums中下标i的数 在新的排序中的下标为target[i]
    for (int i = 0; i < numsSize; i++) targets[i] = -1;
    *returnSize = 0;
    permute(nums, numsSize, 0, targets, permutations, returnSize);
    return permutations;
}

int main(int argc, char const* argv[]) {
    int length = 3;
    int nums[100] = {1, 2, 2};
    int returnSize;
    int** arrays = permuteUnique(nums, length, &returnSize);
    print_int_arrays(arrays, returnSize, length);
    return 0;
}
