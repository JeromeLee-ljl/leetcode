// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

// Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up :
// If you have figured out the O(n) solution, try coding another solution using
// the divide and conquer approach, which is more subtle.

#include "../include/tools.cpp"
int maxSubArray(int* nums, int numsSize) {
    if (numsSize < 1) return 0;
    int max_sum = nums[0];
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (sum < 0) {
            sum = nums[i];
        } else {
            sum += nums[i];
        }
        max_sum = sum > max_sum ? sum : max_sum;
    }
    return max_sum;
}

typedef struct {
    int left;
    int right;
    int sum;
    int max;
} Info;

int max(int a, int b) { return a > b ? a : b; }

Info divide_conquer(int* sum, int left, int right) {
    if (left == right) {
        Info c = { sum[left], sum[left], sum[left], sum[left] };
        return c;
    }
    Info a = divide_conquer(sum, left, (left + right) / 2);
    Info b = divide_conquer(sum, (left + right) / 2 + 1, right);
    Info c;
    c.left = max(a.left, a.sum + b.left);
    c.right = max(b.right, b.sum + a.right);
    c.sum = a.sum + b.sum;
    c.max = max(max(a.max, b.max), a.right + b.left);
    return c;
}

int maxSubArray2(int* nums, int numsSize) {
    if (numsSize < 1) return 0;
    return divide_conquer(nums, 0, numsSize - 1).max;
}

int main(int argc, char const* argv[]) {
    int len = 3;
    int a[3] = {-1,0,-2};
    printf("%d\n", maxSubArray2(a, len));
    getchar();
    return 0;
}
