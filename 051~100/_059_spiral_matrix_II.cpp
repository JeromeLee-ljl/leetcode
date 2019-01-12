// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral
// order.

// Example:
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "../include/tools.cpp"

void generat(int** matrix, int top_left, int bottom_right, int start) {
    if (top_left > bottom_right) return;
    if (top_left == bottom_right) matrix[top_left][top_left] = start;
    for (int i = top_left; i < bottom_right; i++) { //top
        matrix[top_left][i] = start++;
    }
    for (int i = top_left; i < bottom_right; i++) { //right
        matrix[i][bottom_right] = start++;
    }
    for (int i = bottom_right; i > top_left; i--) { //bottom
        matrix[bottom_right][i] = start++;
    }
    for (int i = bottom_right; i > top_left; i--) { //left
        matrix[i][top_left] = start++;
    }
    generat(matrix, top_left + 1, bottom_right - 1, start);
}

int** generateMatrix(int n) {
    int** matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] =  (int*)malloc(sizeof(int) * n);
    }
    generat(matrix, 0, n - 1, 1);
    return matrix;
}

int main(int argc, char const *argv[])
{
    int n=3;
    print_arrays(generateMatrix(n),n,n);    
    getchar();
    return 0;
}
