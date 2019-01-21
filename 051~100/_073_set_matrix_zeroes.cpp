// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

// Example 1:
// Input:
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output:
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]

// Example 2:
// Input:
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output:
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]

// Follow up:
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

#include "../include/tools.cpp"


// space O(row+col)
void setZeroes1(int** matrix, int matrixRowSize, int matrixColSize) {
    int* rows = (int*)calloc(matrixRowSize, sizeof(int));
    int* cols = (int*)calloc(matrixColSize, sizeof(int));

    for (int row = 0; row < matrixRowSize; row++) {
        for (int col = 0; col < matrixColSize; col++) {
            if (matrix[row][col] == 0) {
                rows[row] = 1;
                cols[col] = 1;
            }
        }
    }
    for (int row = 0; row < matrixRowSize; row++) {
        if (rows[row] == 0) continue;
        for (int col = 0; col < matrixColSize; col++) {
            matrix[row][col] = 0;
        }
    }
    for (int col = 0; col < matrixColSize; col++) {
        if (cols[col] == 0) continue;
        for (int row = 0; row < matrixRowSize; row++) {
            matrix[row][col] = 0;
        }
    }
    free(rows);
    free(cols);
}
// space O(row+col)
void setZeroes2(int** matrix, int matrixRowSize, int matrixColSize) {
    int* rows = (int*)calloc(matrixRowSize, sizeof(int));
    int* cols = (int*)calloc(matrixColSize, sizeof(int));

    for (int row = 0; row < matrixRowSize; row++) {
        for (int col = 0; col < matrixColSize; col++) {
            if (matrix[row][col] == 0) {
                rows[row] = 1;
                cols[col] = 1;
            }
        }
    }
    for (int row = 0; row < matrixRowSize; row++) {
        for (int col = 0; col < matrixColSize; col++) {
            if (rows[row] || cols[col]) {
                matrix[row][col] = 0;
            }
        }
    }
    free(rows);
    free(cols);
}
// space O(col)
void setZeroes3(int** matrix, int matrixRowSize, int matrixColSize) {
    int* cols = (int*)calloc(matrixColSize, sizeof(int));

    for (int row = 0; row < matrixRowSize; row++) {
        int flag = 0;
        for (int col = 0; col < matrixColSize; col++) {
            if (matrix[row][col]) continue;
            flag = 1;
            cols[col] = 1;
        }
        if (!flag) continue;
        for (int col = 0; col < matrixColSize; col++) {
            matrix[row][col] = 0;
        }
    }
    for (int col = 0; col < matrixColSize; col++) {
        if (!cols[col]) continue;
        for (int row = 0; row < matrixRowSize; row++) {
            matrix[row][col] = 0;
        }
    }
    free(cols);
}

// space O(col)
void setZeroes4(int** matrix, int matrixRowSize, int matrixColSize) {
    int* cols = (int*)calloc(matrixColSize, sizeof(int));

    for (int row = 0; row < matrixRowSize; row++) {
        for (int col = 0; col < matrixColSize; col++) {
            if (matrix[row][col]) continue;
            for (int col_1 = 0; col_1 < matrixColSize; col_1++) {
                if (matrix[row][col_1] == 0) {
                    cols[col_1] = 1;
                }
                matrix[row][col_1] = 0;
            }
            break;
        }
    }
    for (int col = 0; col < matrixColSize; col++) {
        if (!cols[col]) continue;
        for (int row = 0; row < matrixRowSize; row++) {
            matrix[row][col] = 0;
        }
    }
    free(cols);
}

// space O(1)
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int flag_row = 0, flag_col = 0;
    for (int col = 0; col < matrixColSize; col++) {
        if (matrix[0][col] == 0) {
            flag_row = 1;
            break;
        }
    }
    for (int row = 0; row < matrixRowSize; row++) {
        if (matrix[row][0] == 0) {
            flag_col = 1;
            break;
        }
    }
    for (int row = 1; row < matrixRowSize; row++) {
        for (int col = 1; col < matrixColSize; col++) {
            if (matrix[row][col] == 0) {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }
    for (int row = 1; row < matrixRowSize; row++) {
        for (int col = 1; col < matrixColSize; col++) {
            if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                matrix[row][col] = 0;
            }
        }
    }
    if (flag_row) {
        for (int col = 0; col < matrixColSize; col++) {
            matrix[0][col] = 0;
        }
    }
    if (flag_col) {
        for (int row = 1; row < matrixRowSize; row++) {
            matrix[row][0] = 0;
        }
    }
}