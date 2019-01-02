// Given an array of non-negative integers, you are initially positioned at the
// first index of the array. Each element in the array represents your maximum
// jump length at that position. Determine if you are able to reach the last
// index.

// Example 1:
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last
//              index.
#include <stdio.h>
bool canJump(int *nums, int numsSize) {
    int max_i = 0;
    for (int i = 0; i < numsSize; i++) {
        if (max_i >= numsSize - 1) return true;
        if (i > max_i) break;
        max_i = i + nums[i] > max_i ? i + nums[i] : max_i;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int a[7] = {3, 0, 8, 2, 0, 0, 1};
    int b[1] = {0};
    printf("%d", canJump(b, 1));

    getchar();
    return 0;
}
