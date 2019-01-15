// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
char* addBinary(char* a, char* b) {
    int a_len = strlen(a), b_len = strlen(b);
    int max_len = a_len > b_len ? a_len : b_len;
    char* res = (char*)calloc(max_len + 2, sizeof(char));

    char carry = 0;
    char a_bit, b_bit;
    for (int a_i = a_len - 1, b_i = b_len - 1, res_i = max_len; a_i >= 0 || b_i >= 0;
         a_i--, b_i--, res_i--) {
        a_bit = a_i < 0 ? 0 : a[a_i] - '0';
        b_bit = b_i < 0 ? 0 : b[b_i] - '0';
        res[res_i] = a_bit ^ b_bit ^ carry + '0';
        carry = a_bit & b_bit | (a_bit | b_bit) & carry;
    }
    res[0] = carry + '0';
    if (!carry) res++;
    return res;
}