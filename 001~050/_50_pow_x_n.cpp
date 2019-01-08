// Implement pow(x, n), which calculates x raised to the power n (xn).

// Example 1:

// Input: 2.00000, 10
// Output: 1024.0000
#include "../include/tools.h"

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) {
        return 1 / myPow(x, -(n + 1)) / x;
    }
    double value = myPow(x, n / 2);
    value *= value;
    return n % 2 ? value * x : value;
}   

int main(int argc, char const *argv[]) {
    printf("%f\n", myPow(2.00000, -2147483648));

    getchar();
    return 0;
}
