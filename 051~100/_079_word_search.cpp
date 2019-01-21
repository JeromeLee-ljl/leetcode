// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells
// are those horizontally or vertically neighboring. The same letter cell may not be used more than
// once.

// Example:
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#include <stdlib.h>
///////////////////////      1
bool _dfs(char** board, int boardRowSize, int boardColSize, int row, int col, char* word,
          int** is_used) {
    if (*word == '\0') return 1;

    is_used[row][col] = 1;
    if (row > 0 && board[row - 1][col] == *word && !is_used[row - 1][col]) {
        if (_dfs(board, boardRowSize, boardColSize, row - 1, col, word + 1, is_used)) return 1;
    }
    if (col > 0 && board[row][col - 1] == *word && !is_used[row][col - 1]) {
        if (_dfs(board, boardRowSize, boardColSize, row, col - 1, word + 1, is_used)) return 1;
    }
    if (row < boardRowSize - 1 && board[row + 1][col] == *word && !is_used[row + 1][col]) {
        if (_dfs(board, boardRowSize, boardColSize, row + 1, col, word + 1, is_used)) return 1;
    }
    if (col < boardColSize - 1 && board[row][col + 1] == *word && !is_used[row][col + 1]) {
        if (_dfs(board, boardRowSize, boardColSize, row, col + 1, word + 1, is_used)) return 1;
    }
    is_used[row][col] = 0;
    return 0;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int** is_used = (int**)malloc(sizeof(int*) * boardRowSize);
    for (int i = 0; i < boardRowSize; i++) {
        is_used[i] = (int*)calloc(boardColSize, sizeof(int));
    }
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == word[0]) {
                if (_dfs(board, boardRowSize, boardColSize, i, j, word + 1, is_used)) return 1;
            }
        }
    }
    for (int i = 0; i < boardRowSize; i++) {
        free(is_used[i]);
    }
    free(is_used);
    return 0;
}

/////////////////////  2
bool _dfs(char** board, int boardRowSize, int boardColSize, int row, int col, char* word,
          int** is_used) {
    if (*word == '\0') return 1;
    if (row < 0 || col < 0 || row >= boardRowSize || col >= boardColSize) return 0;
    if (board[row][col] != *word || is_used[row][col]) return 0;

    is_used[row][col] = 1;
    int res = _dfs(board, boardRowSize, boardColSize, row - 1, col, word + 1, is_used) ||
              _dfs(board, boardRowSize, boardColSize, row + 1, col, word + 1, is_used) ||
              _dfs(board, boardRowSize, boardColSize, row, col - 1, word + 1, is_used) ||
              _dfs(board, boardRowSize, boardColSize, row, col + 1, word + 1, is_used);
    is_used[row][col] = 0;
    return res;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int** is_used = (int**)malloc(sizeof(int*) * boardRowSize);
    for (int i = 0; i < boardRowSize; i++) {
        is_used[i] = (int*)calloc(boardColSize, sizeof(int));
    }
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (_dfs(board, boardRowSize, boardColSize, i, j, word, is_used)) return 1;
        }
    }
    for (int i = 0; i < boardRowSize; i++) {
        free(is_used[i]);
    }
    free(is_used);
    return 0;
}

///////////////////////// 3
bool _dfs(char** board, int boardRowSize, int boardColSize, int row, int col, char* word) {
    if (*word == '\0') return 1;
    if (row < 0 || col < 0 || row >= boardRowSize || col >= boardColSize) return 0;
    if (board[row][col] != *word) return 0;

    board[row][col] ^= 0x80;
    int res = _dfs(board, boardRowSize, boardColSize, row - 1, col, word + 1) ||
              _dfs(board, boardRowSize, boardColSize, row + 1, col, word + 1) ||
              _dfs(board, boardRowSize, boardColSize, row, col - 1, word + 1) ||
              _dfs(board, boardRowSize, boardColSize, row, col + 1, word + 1);
    board[row][col] ^= 0x80;
    return res;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (_dfs(board, boardRowSize, boardColSize, i, j, word)) return 1;
        }
    }
    return 0;
}
