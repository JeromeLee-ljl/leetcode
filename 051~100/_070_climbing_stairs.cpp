// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: Given n will be a positive integer.

// Example 1:
// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

int combination(int k, int n) {
    k = n - k < k ? n - k : k;
    long long res = 1;

    for (int i = n, j = 1; i > n - k || j <= k; i--, j++) {
        if (i > n - k) res *= i;
        if (j <= k) res /= j;
    }
    return res;
}

int climbStairs(int n) {
    int odd, count = 0;
    for (int even = 0; even * 2 <= n; even++) {
        odd = n - even * 2;
        count += combination(even, even + odd);
    }
    return count;
}

int climbStairs2(int n) {
    int* arr = (int*)malloc(sizeof(int) * (n + 1));
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int res = arr[n];
    free(arr);
    return res;
}

int climbStairs3(int n) {
    int pri = 1, cur = 1, tmp;
    for (int i = 2; i <= n; i++) {
        tmp = pri;
        pri = cur;
        cur += tmp;
    }
    return cur;
}
int climbStairs4(int n) {
    int pri = 1, cur = 1;
    while(n--){
        pri = (cur+=pri) - pri;
    }
    return pri;
}

