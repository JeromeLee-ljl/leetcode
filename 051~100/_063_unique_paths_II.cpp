// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach
// the bottom-right corner of the grid (marked 'Finish' in the diagram below). Now consider if some
// obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Note: m and n will be at most 100.

// Example 1:
// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2

#include "../include/tools.cpp"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if (!obstacleGrid || obstacleGridColSize < 1 || obstacleGridRowSize < 1) return 0;
    int* dp = (int*)calloc(obstacleGridColSize + 1, sizeof(int));
    dp[1] = 1;

    for (int i = 0; i <obstacleGridRowSize; i++) {
        for (int j = 0; j < obstacleGridColSize; j++) {
            if (obstacleGrid[i][j]) {
                dp[j+1] = 0;
            } else {
                dp[j+1] += dp[j];
            }
        }
    }
    int count = dp[obstacleGridColSize];
    free(dp);
    return count;
}
