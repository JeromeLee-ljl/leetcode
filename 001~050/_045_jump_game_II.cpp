// Given an array of non-negative integers, you are initially positioned at the
// first index of the array. Each element in the array represents your maximum
// jump length at that position. Your goal is to reach the last index in the
// minimum number of jumps.

// Example:
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.

#include <stdio.h>

int jump(int* nums, int numsSize) {
    // if (numsSize <= 1) return 0;
    // int i = 0, count = 1, max_i;
    // while (i < numsSize) {
    //     if (i + nums[i] >= numsSize - 1) break;
    //     max_i = i + 1;
    //     for (int j = i + 2; j <= i + nums[i]; j++) {
    //         if (j + nums[j] > max_i + nums[max_i]) {
    //             max_i = j;
    //         }
    //     }
    //     i = max_i;
    //     count++;
    // }
    // return count;

    int count = 0, max_i = 0, max = 0;
    for (int i = 1; i < numsSize-1; i++) {
        if (i + nums[i] > max) max = i + nums[i];
        if (i == max_i) {
            max_i = max;
            count++;
        }
    }
    return count;
}

int main(int argc, char const* argv[]) {
    int a[2] = {2, 1};
    printf("%d", jump(a, 2));
    getchar();
    return 0;
}
