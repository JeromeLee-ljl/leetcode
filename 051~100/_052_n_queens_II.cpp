// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other. Given an integer n, return the
// number of distinct solutions to the n-queens puzzle.

// Example:
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown
// below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

#include "../include/tools.cpp"

#define Bool char
#define True 1
#define False 0

typedef struct {
    Bool* col;         //  列
    Bool* slash;       //  '/'
    Bool* back_slash;  //  '\'
    int n;
    int count;
} QueenBoard;

QueenBoard* queen_board_create(int n) {
    QueenBoard* board = (QueenBoard*)malloc(sizeof(QueenBoard));
    board->col = (Bool*)malloc(sizeof(Bool) * 5 * n);
    board->slash = board->col + n;
    board->back_slash = board->col + 3 * n;
    board->n = n;
    board->count = 0;
    memset(board->col, 0, sizeof(Bool) * 5 * n);
    return board;
}

void queen_board_free(QueenBoard* board) {
    free(board->col);
    free(board);
}

Bool queen_board_set(QueenBoard* board, int row, int col) {
    if (board->col[col]) return False;
    if (board->slash[row + col]) return False;
    if (board->back_slash[board->n - 1 - row + col]) return False;
    board->col[col] = True;
    board->slash[row + col] = True;
    board->back_slash[board->n - 1 - row + col] = True;
    return True;
}

void queen_board_recovery(QueenBoard* board, int row, int col) {
    board->col[col] = False;
    board->slash[row + col] = False;
    board->back_slash[board->n - 1 - row + col] = False;
}

void queen_board_solve(QueenBoard* board, int row) {
    if (row == board->n) {
        board->count++;
        return;
    }
    for (int col = 0; col < board->n; col++) {
        if (queen_board_set(board, row, col)) {
            queen_board_solve(board, row + 1);
            queen_board_recovery(board, row, col);
        }
    }
}

int totalNQueens(int n) {
    if (n < 1) return NULL;
    QueenBoard* board = queen_board_create(n);
    queen_board_solve(board, 0);
    int returnSize = board->count;
    queen_board_free(board);
    return returnSize;
}

int count_by_bitmap(int n, int row, int left_disable, int down_disable,
           int right_disable) {
    if (row == n) {
        return 1;
    }
    int count = 0;
    int width = (1 << n) - 1;
    int usable = width & ~(left_disable | down_disable | right_disable);

    while (usable != 0) {
        int first_usable = -usable & usable;
        count += count_by_bitmap(n, row + 1, (left_disable | first_usable) << 1, down_disable | first_usable, (right_disable | first_usable) >> 1);
        usable ^= first_usable;
    }
    return count;
}

int totalNQueens2(int n) {
    if (n < 1) return NULL;
    return count_by_bitmap(n, 0, 0, 0, 0);
}

int main(int argc, char const* argv[]) {
    int n = 5;
    printf("%d", totalNQueens2(n));
    getchar();
    return 0;
}