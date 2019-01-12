// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return
// the length of last word in the string.
// If the last word does not exist, return 0.
// Note: A word is defined as a character sequence consists of non-space characters only.

// Example:
// Input: "Hello World"
// Output: 5

int lengthOfLastWord(char* s) {
    int length = 0;
    for (; *s != '\0'; s++) {
        if (*s == ' ') continue;  // skip whitespace
        length = 0;
        for (; *s != ' ' && *s != '\0'; s++) length++;  // count length
        s--;
    }
    return length;
}