// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
// which minimizes the sum of all numbers along its path. Note: You can only move either down or
// right at any point in time.

// Example:
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
#include "../include/tools.cpp"

int min(int a, int b) { return a < b ? a : b; }

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int* dp = (int*)malloc(sizeof(int) * (gridColSize + 1));
    for (int i = 0; i <= gridColSize; i++) {
        dp[i] = INT_MAX;
    }
    dp[1] = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            dp[j + 1] = min(dp[j], dp[j + 1]) + grid[i][j];
        }
    }
    int min_path_sum = dp[gridColSize];
    free(dp);
    return min_path_sum;
}