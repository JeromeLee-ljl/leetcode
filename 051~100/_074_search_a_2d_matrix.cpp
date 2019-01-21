// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the
// following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Example 1:
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true

// Example 2:
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

bool searchMatrix1(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (!matrix || matrixRowSize < 1 || matrixColSize < 1 || matrix[0][0] > target) return 0;
    int left = 0, right = matrixRowSize - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target > matrix[mid][matrixColSize - 1]) {
            left = mid + 1;
        } else if (target < matrix[mid][0]) {
            right = mid - 1;
        } else if (target >= matrix[mid][0] && target <= matrix[mid][matrixColSize - 1]) {
            int* row = matrix[mid];
            left = 0;
            right = matrixColSize - 1;
            while (left < right) {
                mid = (left + right) / 2;
                if (target > row[mid]) {
                    left = mid + 1;
                } else if (target < row[mid]) {
                    right = mid - 1;
                } else {
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (!matrix) return 0;
    int left = 0, right = matrixRowSize * matrixColSize - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target > matrix[mid / matrixColSize][mid % matrixColSize]) {
            left = mid + 1;
        } else if (target < matrix[mid / matrixColSize][mid % matrixColSize]) {
            right = mid - 1;
        } else {
            return 1;
        }
    }
    return 0;
}