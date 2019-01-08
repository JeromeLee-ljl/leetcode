// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
// Note:
// You have to rotate the image in-place, which means you have to modify the
// input 2D matrix directly. DO NOT allocate another 2D matrix and do the
// rotation.

// Example 1:
// Given input matrix =
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

// Example 2:
// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ],
// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]
#include "../include/tools.cpp"

void rotate(int** matrix, int matrixRowSize, int* matrixColSizes) {
    int row, col, temp;
    for (row = 0; row < matrixRowSize / 2; row++) {
        for (col = row; col < matrixRowSize - 1 - row; col++) {
            temp = matrix[row][col];
            matrix[row][col] = matrix[matrixRowSize - 1 - col][row];
            matrix[matrixRowSize - 1 - col][row] = matrix[matrixRowSize - 1 - row][matrixRowSize - 1 - col];
            matrix[matrixRowSize - 1 - row][matrixRowSize - 1 - col] = matrix[col][matrixRowSize - 1 - row];
            matrix[col][matrixRowSize - 1 - row] = temp;
        }
    }
}

int main(int argc, char const* argv[]) {
    int **a, **b;
    int *c[3], *d[4];
    int e[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int f[4][4] = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    for (int i = 0; i < 3; i++) {
        c[i] = e[i];
    }
    for (int i = 0; i < 4; i++) {
        d[i] = f[i];
    }
    a = c;
    b = d;

    int m;
    print_int_arrays(a, 3, 3);
    rotate(a, 3, &m);
    printf("\n");
    print_int_arrays(a, 3, 3);
    printf("\n");
    print_int_arrays(b, 4, 4);
    rotate(b, 4, &m);
    printf("\n");
    print_int_arrays(b, 4, 4);
    return 0;
}
