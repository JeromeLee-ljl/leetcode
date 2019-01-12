// The set [1,2,3,...,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n =
// 3: "123" "132" "213" "231" "312" "321" Given n and k, return the kth permutation sequence.

// Note:
// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"

#include "../include/tools.cpp"

char* getPermutation(int n, int k) {
    char* res = (char*)malloc(sizeof(char) * (n + 1));
    char* set = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) set[i] = i + '1';
    res[n] = set[n] = '\0';
    k--;

    int size = 1;
    for (int i = 1; i <= n; i++) size *= i;
    for (int res_i = 0, set_i; res_i < n; res_i++) {
        size /= (n - res_i);
        set_i = k / size;
        k %= size;
        res[res_i] = set[set_i];
        for (int i = set_i; i < n - res_i; i++) {  // delete set[set_i]
            set[i] = set[i + 1];
        }
    }
    return res;
}

int main(int argc, char const* argv[]) {
    printf("%s", getPermutation(3, 5));

    getchar();
    return 0;
}
