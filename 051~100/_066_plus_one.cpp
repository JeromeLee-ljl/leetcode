// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each
// element in the array contain a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int* res = (int*)malloc(sizeof(int) * (digitsSize + 1));
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (carry + digits[i] == 10) {
            res[i] = 0;
            carry = 1;
        } else {
            res[i] = carry + digits[i];
            carry = 0;
        }
    }
    *returnSize = digitsSize;
    if (carry) {
        for (int i = digitsSize; i > 0; i--) {
            res[i] = res[i - 1];
        }
        res[0] = 1;
        (*returnSize)++;
    }
    return res;
}