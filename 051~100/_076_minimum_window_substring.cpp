// Given a string S and a string T, find the minimum window in S which will contain all the
// characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum
// window in S.
#include "../include/tools.cpp"

char* minWindow1(char* s, char* t) {
    int nums[64];
    for (int i = 0; i < 64; i++) {
        nums[i] = INT_MIN;
    }

    int s_len = strlen(s), t_len = strlen(t), count = 0;
    for (int i = 0; i < t_len; i++) {
        if (nums[t[i] - 'A'] == INT_MIN) {
            count++;
            nums[t[i] - 'A'] = 0;
        }
        nums[t[i] - 'A']++;
    }

    int left = 0, right = 0, min_w = INT_MAX, min_l = 0, min_r = 0;
    for (; right < s_len; right++) {
        if (nums[s[right] - 'A'] == INT_MIN) continue;
        if (--nums[s[right] - 'A'] == 0) count--;

        for (; count == 0 && left <= right; left++) {
            if (nums[s[left] - 'A'] == INT_MIN) continue;
            if (nums[s[left] - 'A']++ == 0) {
                count++;
            }
            if (right - left < min_w) {
                min_l = left;
                min_r = right;
                min_w = min_r - min_l;
            }
        }
    }

    if (min_w == INT_MAX) min_w = -1;
    char* res = (char*)calloc(min_w + 2, sizeof(char));
    for (int i = 0; i <= min_w; i++) {
        res[i] = s[min_l + i];
    }
    return res;
}
char* minWindow(char* s, char* t) {
    int nums[64];
    for (int i = 0; i < 64; i++) {
        nums[i] = INT_MAX;
    }

    int count = 0;
    for (int i = 0; t[i] != '\0'; i++) {
        if (nums[t[i] - 'A'] == INT_MAX) {
            nums[t[i] - 'A'] = 1;
            count++;
        } else {
            nums[t[i] - 'A']++;
        }
    }

    int left = 0, right = 0, min_w = INT_MAX, min_l = 0, min_r = 0;
    for (; s[right] != '\0'; right++) {
        printf("right:%d\n", right);
        if (--nums[s[right] - 'A'] == 0) count--;
        while (count == 0) {
            printf("left:%d\n", left);
            if (right - left < min_w) {
                min_l = left;
                min_r = right;
                min_w = min_r - min_l;
            }
            if (nums[s[left] - 'A'] == 0) break;
            nums[s[left++] - 'A']++;
        }
    }

    if (min_w == INT_MAX) min_w = -1;
    
    char* res = (char*)calloc(min_w + 2, sizeof(char));
    for (int i = 0; i <= min_w; i++) {
        res[i] = s[min_l + i];
    }
    return res;
}

int main(int argc, char const* argv[]) {
    char a[] = "ADOBECODEBANC";
    char b[] = "ABC";

    printf("%s\n", minWindow(a, b));

    getchar();
    return 0;
}
