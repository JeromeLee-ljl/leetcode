// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach
// the bottom-right corner of the grid (marked 'Finish' in the diagram below). How many possible
// unique paths are there? Above is a 7 x 3 grid. How many possible unique paths are there?

// Note: m and n will be at most 100.

// Example 1:
// Input: m = 3, n = 2
// Output: 3

// Example 2:
// Input: m = 7, n = 3
// Output: 28
#include "../include/tools.cpp"

// recursive    slow
int uniquePaths(int m, int n) {
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += uniquePaths(m - 1, i + 1);
    }
    return count;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int count_path(int m, int n, int** temp) {
    if (m > n) swap(&m, &n);
    if (m == 1) return 1;
    if (temp[m - 1][n - 1]) return temp[m - 1][n - 1];

    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += count_path(m - 1, i, temp);
    }
    temp[m - 1][n - 1] = count;
    return count;
}
// cache
int uniquePaths2(int m, int n) {
    if (m > n) swap(&m, &n);
    if (m < 1) return 0;
    int** temp = (int**)malloc(sizeof(int*) * m);
    temp[0] = (int*)calloc(n * m, sizeof(int));
    for (int i = 1; i < m; i++) {
        temp[i] = temp[0] + i * sizeof(int);
    }
    // for (int i = 0; i < m; i++) {
    //     temp[i] = (int*)calloc(n, sizeof(int));
    // }
    int count = count_path(m, n, temp);
    // for (int i = 0; i < m; i++) {
    //     free(temp[i]);
    // }
    free(temp[0]);
    free(temp);
    return count;
}
// DP   二维数组
int uniquePaths2(int m, int n) {
    if (m < 1 || n < 1) return 0;
    int* temp = (int*)malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) temp[i] = 1;
    for (int i = 1; i < m; i++) {
        temp[i * n] = 1;
        for (int j = i * n + 1; j < i * n + n; j++) {
            temp[j] = temp[j - 1] + temp[j - n];
        }
    }
    int count = temp[m * n - 1];
    free(temp);
    return count;
}
// DP   一维数组
int uniquePaths3(int m, int n) {
    if (m < 1 || n < 1) return 0;
    int* temp = (int*)calloc(n + 1, sizeof(int));
    temp[1] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp[j+1] += temp[j];
        }
    }
    int count = temp[n];
    free(temp);
    return count;
}

//排列组合
int uniquePaths4(int m, int n) {
    if (m > n) {
        int tmp = m;
        m = n;
        n = tmp;
    }
    if (m < 1) return 0;
    double count = 1;
    // C(n-1, m+n-2)
    for (int i = m + n - 2; i >= n; i--) {
        count *= i;
    }
    for (int i = m - 1; i > 1; i--) {
        count /= i;
    }

    return count;
}
