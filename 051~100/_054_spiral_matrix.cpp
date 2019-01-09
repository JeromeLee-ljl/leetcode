// Given a matrix of
// m x n elements (m
// rows, n columns),
// return all
// elements of the
// matrix in spiral
// order.

// Example 1:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output:
// [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output:
// [1,2,3,4,8,12,11,10,9,5,6,7]

/**
 * Note: The
 * returned array
 * must be malloced,
 * assume caller
 * calls free().
 */
#include "../include/tools.cpp"

void spiral(int** matrix, int top, int right, int bottom, int left, int* order, int start) {
    if (top > bottom || left > right) return;
    for (int i = left; i < right; i++) order[start++] = matrix[top][i];
    for (int i = top; i <= bottom; i++) order[start++] = matrix[i][right];
    if (top == bottom || left == right) return;
    for (int i = right - 1; i > left; i--) order[start++] = matrix[bottom][i];
    for (int i = bottom; i > top; i--) order[start++] = matrix[i][left];
    spiral(matrix, top + 1, right - 1, bottom - 1, left + 1, order, start);
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int* spiral_order = (int*)malloc(sizeof(int) * matrixRowSize * matrixColSize);
    spiral(matrix, 0, matrixColSize - 1, matrixRowSize - 1, 0, spiral_order, 0);
    return spiral_order;
}

int main(int argc, char const* argv[]) {
    int matrixRowSize = 1;
    int matrixColSize = 10;
    int tmp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* a[1] = {tmp};
    int* sp = spiralOrder(a, matrixRowSize, matrixColSize);
    print_array(sp, matrixRowSize * matrixColSize);
    getchar();
    return 0;
}
