// The n-queen puzzle is the problem of placing n queen on an n×n chessboard
// such that no two queen attack each other. Given an integer n, return all
// distinct solutions to the n-queen puzzle. Each solution contains a distinct
// board configuration of the n-queen' placement, where 'Q' and '.' both
// indicate a queen and an empty space respectively.

// Example:
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queen puzzle as
// shown above.

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "../include/tools.cpp"

#define Bool char
#define True 1
#define False 0

typedef struct {
    Bool* col;         //  列
    Bool* slash;       //  '/'
    Bool* back_slash;  //  '\'
    int n;
    char** board;
} QueenBoard;

QueenBoard* queen_board_create(int n) {
    QueenBoard* board = (QueenBoard*)malloc(sizeof(QueenBoard));

    board->col = (Bool*)malloc(sizeof(Bool) * 5 * n);
    board->slash = board->col + n;
    board->back_slash = board->col + 3 * n;
    board->n = n;
    board->board = (char**)malloc(sizeof(char*) * n);
    board->board[0] = (char*)malloc(sizeof(char) * n * (n + 1));

    memset(board->col, 0, sizeof(Bool) * 5 * n);
    memset(board->board[0], '.', sizeof(char) * n * (n + 1));
    for (int i = 0; i < n; i++) {
        board->board[i] = board->board[0] + i * (n + 1);
        board->board[i][n] = '\0';
    }
    return board;
}

void queen_board_free(QueenBoard* board) {
    free(board->col);
    free(board->board[0]);
    free(board->board);
    free(board);
}

Bool queen_board_set(QueenBoard* board, int row, int col) {
    if (board->col[col]) return False;
    if (board->slash[row + col]) return False;
    if (board->back_slash[board->n - 1 - row + col]) return False;
    board->col[col] = True;
    board->slash[row + col] = True;
    board->back_slash[board->n - 1 - row + col] = True;
    board->board[row][col] = 'Q';
    // print_array("set", board->board, board->n);
    return True;
}

void queen_board_recovery(QueenBoard* board, int row, int col) {
    board->col[col] = False;
    board->slash[row + col] = False;
    board->back_slash[board->n - 1 - row + col] = False;
    board->board[row][col] = '.';
    // print_array("recovery", board->board, board->n);
}

#define ullong unsigned long long
void mem_copy(void* dst, void* src, unsigned int size) {
    char* dst_c_p = (char*)dst;
    char* src_c_p = (char*)src;
    for (; (ullong)dst_c_p & (sizeof(ullong) - 1) != 0; dst_c_p++, src_c_p++) {
        *src_c_p = *dst_c_p;
    }
    ullong* dst_p = (ullong*)dst_c_p;
    ullong* src_p = (ullong*)src_c_p;
    char* end_p = (char*)dst + size - sizeof(ullong);
    for (; (char*)dst_p <= end_p; dst_p++, src_p++) {
        *dst_p = *src_p;
    }
    dst_c_p = (char*)dst_p;
    src_c_p = (char*)src_p;
    char* end_c_p = (char*)dst + size;
    for (; dst_c_p < end_c_p; dst_c_p++, src_c_p++) {
        *dst_c_p = *src_c_p;
    }
}

char** queen_board_copy(QueenBoard* board) {
    int n = board->n;
    char** strs = (char**)malloc(sizeof(char*) * n);
    strs[0] = (char*)malloc(sizeof(char) * (n + 1) * n);
    for (int i = 0; i < n; i++) {
        strs[i] = strs[0] + i * (n + 1);
    }
    mem_copy(strs[0], board->board[0], (n + 1) * n);
    return strs;
}

void queen_board_solve(QueenBoard* board, int row, char*** solves, int* size) {
    if (row == board->n) {
        solves[(*size)++] = queen_board_copy(board);
        return;
    }
    for (int col = 0; col < board->n; col++) {
        if (queen_board_set(board, row, col)) {
            queen_board_solve(board, row + 1, solves, size);
            queen_board_recovery(board, row, col);
        }
    }
}

char*** solveNQueens(int n, int* returnSize) {
    *returnSize = 0;
    if (n < 1) return NULL;
    QueenBoard* board = queen_board_create(n);
    int len = 1;
    for (int i = 2; i <= n; i++) len *= i;
    char*** solves = (char***)malloc(sizeof(char**) * len);

    queen_board_solve(board, 0, solves, returnSize);
    queen_board_free(board);
    return solves;
}

int main(int argc, char const* argv[]) {
    int size;
    int n = 5;
    char*** solves = solveNQueens(n, &size);
    printf("{\n");
    for (int i = 0; i < size; i++) {
        print_array(" ", solves[i], n);
    }
    printf("}");
    getchar();
    return 0;
}
