// Given an array of words and a width maxWidth, format the text such that each line has exactly
// maxWidth characters and is fully (left and right) justified. You should pack your words in a
// greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when
// necessary so that each line has exactly maxWidth characters. Extra spaces between words should be
// distributed as evenly as possible. If the number of spaces on a line do not divide evenly between
// words, the empty slots on the left will be assigned more spaces than the slots on the right. For
// the last line of text, it should be left justified and no extra space is inserted between words.

// Note:
// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.

// Example 1:
// Input:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "../include/tools.cpp"

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    int* lengths = (int*)malloc(sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        lengths[i] = strlen(words[i]);
    }

    for (int start, end = 0; end < wordsSize;) {
        start = end;
        int total = 0;
        for (; end < wordsSize && total + lengths[end] + end - start <= maxWidth; end++) {
            total += lengths[end];
        }

        char* str = (char*)calloc(maxWidth + 1, sizeof(char));
        memset(str, ' ', maxWidth);
        if (end == wordsSize) {
            for (int i = start, str_i = 0; i < end; i++) {
                memcpy(str + str_i, words[i], lengths[i]);
                str_i += lengths[i] + 1;
            }
        } else {
            int all_space = maxWidth - total;
            memcpy(str, words[start], lengths[start]);
            for (int i = start + 1, str_i = 0; i < end; i++) {
                int space = all_space / (end - i) + (all_space % (end - i) > 0);
                str_i += lengths[i - 1] + space;
                all_space -= space;
                memcpy(str + str_i, words[i], lengths[i]);
            }
        }
        res[(*returnSize)++] = str;
    }
    free(lengths);
    return res;
}