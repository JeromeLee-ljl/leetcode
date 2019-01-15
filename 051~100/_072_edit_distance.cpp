// Given two words word1 and word2, find the minimum number of operations required to convert word1
// to word2. You have the following 3 operations permitted on a word: Insert a character Delete a
// character Replace a character

// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

#include "../include/tools.cpp"

int min(int x, int y) { return x < y ? x : y; }

int _minDistance(char* word1, char* word2, int iw, int jw, int** temp) {
    // printf("enter:%d,%d\n",iw,jw);
    int l_1 = strlen(word1), l_2 = strlen(word2);
    if (!(l_1 && l_2)) {
        return l_1 > l_2 ? l_1 : l_2;
    }
    if (temp[iw][jw] != 0) return temp[iw][jw];
    int min_dis = INT_MAX;
    for (int i = 0; i < l_1; i++) {
        min_dis =
            min(min_dis, i + (word1[i] != word2[0]) +
                             _minDistance(word1 + i + 1, word2 + 1, iw + i + 1, jw + 1, temp));
    }
    for (int i = 0; i < l_2; i++) {
        min_dis =
            min(min_dis, i + (word2[i] != word1[0]) +
                             _minDistance(word1 + 1, word2 + i + 1, iw + 1, jw + i + 1, temp));
    }
    temp[iw][jw] = min_dis;
    return min_dis;
}
int minDistance1(char* word1, char* word2) {
    printf("len:%d,%d\n", strlen(word1), strlen(word2));
    int** temp = (int**)malloc(sizeof(int*) * (strlen(word1) + 1));
    for (int i = 0; i <= strlen(word1); i++) {
        temp[i] = (int*)malloc(sizeof(int) * (strlen(word2) + 1));
        memset(temp[i], 0, strlen(word2) * sizeof(int));
    }
    return _minDistance(word1, word2, 0, 0, temp);
}

int min(int x, int y) { return x < y ? x : y; }
int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1), len2 = strlen(word2);
    int* dp = (int*)malloc(sizeof(int) * (len2 + 1));
    for (int i = 0; i <= len2; i++) dp[i] = i;
    for (int i_1 = 1; i_1 <= len1; i_1++) {
        int temp = dp[0];
        dp[0] = i_1;
        for (int i_2 = 1; i_2 <= len2; i_2++) {
            int dis = min(temp + (word1[i_1 - 1] != word2[i_2 - 1]), min(dp[i_2 - 1], dp[i_2]) + 1);
            temp = dp[i_2];
            dp[i_2] = dis;
        }
    }
    int min_dis = dp[len2];
    free(dp);
    return min_dis;
}

int main(int argc, char const* argv[]) {
    char a[] = "sor";
    char b[] = "or";
    // printf("%d\n", minDistance(a, b));
    printf("%d\n", minDistance(b, a));
    getchar();
    return 0;
}
