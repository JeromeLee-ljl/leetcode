// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include "../include/tools.cpp"

void _combine1(int start, int n, int k, int* temp, int temp_i, int** combinations, int* comb_i) {
    if (k == 0) {
        int* array = (int*)malloc(sizeof(int) * temp_i);
        memcpy(array, temp, temp_i * sizeof(int));
        combinations[(*comb_i)++] = array;
        return;
    }
    for (int i = start; i <= n - k + 1; i++) {
        temp[temp_i] = i;
        _combine1(i + 1, n, k - 1, temp, temp_i + 1, combinations, comb_i);
    }
}
void _combine2(int start, int n, int k, int* temp, int temp_i, int** combinations, int* comb_i) {
    if (k == 0) {
        int* array = (int*)malloc(sizeof(int) * temp_i);
        memcpy(array, temp, temp_i * sizeof(int));
        combinations[(*comb_i)++] = array;
        return;
    }
    if (start <= n - k + 1) {
        _combine2(start + 1, n, k, temp, temp_i, combinations, comb_i);
        temp[temp_i] = start;
        _combine2(start + 1, n, k - 1, temp, temp_i + 1, combinations, comb_i);
    }
}

void _combine3(int n, int k, int old_k, int* temp, int** combinations, int* comb_i) {
    if (k == 0) {
        int* array = (int*)malloc(sizeof(int) * old_k);
        memcpy(array, temp, old_k * sizeof(int));
        combinations[(*comb_i)++] = array;
        return;
    }
    for (int i = n; i >= k; i--) {
        temp[k - 1] = i;
        _combine3(i - 1, k - 1, old_k, temp, combinations, comb_i);
    }
}

int** combine1(int n, int k, int** columnSizes, int* returnSize) {
    if (k <= 0 || k > n) return NULL;
    int len = combination(k, n);
    int** res = (int**)malloc(sizeof(int*) * len);
    *columnSizes = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        (*columnSizes)[i] = k;
    }
    *returnSize = 0;

    int* temp = (int*)malloc(sizeof(int) * k);
    // _combine1(1, n, k, temp, 0, res, returnSize);
    // _combine2(1, n, k, temp, 0, res, returnSize);
    _combine3(n, k, k, temp, res, returnSize);
    free(temp);
    return res;
}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
    if (k <= 0 || k > n) return NULL;
    *columnSizes = (int*)malloc(sizeof(int) * combination(k, n));
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * combination(k, n));

    int* temp = (int*)calloc(k, sizeof(int));
    int temp_i = 0;
    while (temp_i >= 0) {
        temp[temp_i]++;
        if (temp[temp_i] > n) {
            temp_i--;
        } else if (temp_i == k - 1) {
            res[*returnSize] = (int*)malloc(sizeof(int) * k);
            for (int i = 0; i < k; i++) {
                res[*returnSize][i] = temp[i];
            }
            (*columnSizes)[(*returnSize)++] = k;
        } else {
            temp_i++;
            temp[temp_i] = temp[temp_i - 1];
        }
    }
    free(temp);
    return res;
}

int main(int argc, char const* argv[]) {
    int* columnSizes;
    int returnSize;
    int** res = combine1(4, 2, &columnSizes, &returnSize);

    print_arrays(res, returnSize, 2);
    print_array(columnSizes, returnSize);
    getchar();
    return 0;
}
