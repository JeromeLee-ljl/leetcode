// Implement int sqrt(int x).
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits are truncated and only the integer part
// of the result is returned.

// Example 1:
// Input: 4
// Output: 2

// Example 2:
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since
//              the decimal part is truncated, 2 is returned.
#include "../include/tools.cpp"

// 二分查找
int mySqrt(int x) {
    long long left = 1, right = x;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (mid * mid > x) {
            right = mid - 1;
        } else if (mid * mid < x) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    if (left * left > x) left--;
    return left;
}

// 牛顿法
int mySqrt2(int x) {
    long res = x;
    while (res * res > x) {
        res = (res + x / res) / 2;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", mySqrt(2147483647));
    getchar();
    return 0;
}
