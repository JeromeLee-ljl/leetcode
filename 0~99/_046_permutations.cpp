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

#include "../include/tools.cpp"

void _permute(int* nums, int numsSize, int index, int* targets,
              int** permutations, int* returnSize) {
    if (index == numsSize) {
        permutations[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            permutations[*returnSize][targets[i]] = nums[i];
        }
        (*returnSize)++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (targets[i] == -1) {
            targets[i] = index;
            _permute(nums, numsSize, index + 1, targets, permutations,
                     returnSize);
            targets[i] = -1;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int** permutations = (int**)malloc(sizeof(int*) * factorial(numsSize));
    int* targets = (int*)malloc(sizeof(int) * numsSize);
    // nums中下标i的数 在新的排序中的下标为target[i]
    for (int i = 0; i < numsSize; i++) targets[i] = -1;
    *returnSize = 0;
    _permute(nums, numsSize, 0, targets, permutations, returnSize);
    return permutations;
}

int main(int argc, char const* argv[]) {
    int length = 3;
    int nums[100] = {4, 5, 6};
    int returnSize;
    int** permutations = permute(nums, length, &returnSize);
    print_int_arrays(permutations, returnSize, length);
    return 0;
}
