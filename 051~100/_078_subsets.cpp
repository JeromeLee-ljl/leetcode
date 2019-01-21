// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.

// Example:
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include "../include/tools.cpp"

//  1. 递归
//  2。迭代   a 添加数字到已存在的子集  b 如下
//  3. 位图

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int len = my_pow(2, numsSize);
    *columnSizes = (int*)malloc(sizeof(int) * len);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * len);

    int* index_temp = (int*)calloc(numsSize, sizeof(int));
    index_temp[0]=-1;
    int nums_i = 0;
    while (nums_i >= 0) {
         index_temp[nums_i]++;

        (*columnSizes)[*returnSize] = nums_i + 1;
        int* array = (int*)malloc(sizeof(int) * (nums_i + 1));
        for (int i = 0; i <= nums_i; i++) {
            array[i] = nums[index_temp[i]];
        }
        res[(*returnSize)++] = array;

        if (index_temp[nums_i] == numsSize - 1) {
            nums_i--;
        } else {
            nums_i++;
            index_temp[nums_i] = index_temp[nums_i - 1];
        }
    }
    res[*returnSize] = NULL;
    (*columnSizes)[(*returnSize)++] = 0;
    free(index_temp);
    return res;
}

int main(int argc, char const* argv[]) {
    int a[] = {0};
    int* columnSizes;
    int returnSize;

    int** res = subsets(a, 1, &columnSizes, &returnSize);
    print_array(columnSizes, returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("{");
        if (columnSizes[i] > 0) {
            printf("%d", res[i][0]);
            for (int j = 1; j < columnSizes[i]; j++) {
                printf(" ,%d", res[i][j]);
            }
        }
        printf("}\n");
    }
    getchar();
    return 0;
}
