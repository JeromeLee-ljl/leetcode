// Given a collection of intervals, merge all overlapping intervals.

// Example 1:
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

// Example 2:
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Interval {
    int start;
    int end;
};
#define Q_SORT_TYPE struct Interval
#include "../include/tools.cpp"

int compare_Interval(struct Interval a, struct Interval b) {
    return a.start - b.start;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    *returnSize = 0;
    if (intervalsSize < 1) return NULL;

    quick_sort(intervals, 0, intervalsSize - 1, compare_Interval);

    struct Interval* result = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);
    result[*returnSize].start = intervals[0].start;
    result[*returnSize].end = intervals[0].end;
    for (int i = 1; i < intervalsSize; i++) {
        if (result[*returnSize].end < intervals[i].start) {
            result[++(*returnSize)].start = intervals[i].start;
            result[*returnSize].end = intervals[i].end;
        } else if (result[*returnSize].end < intervals[i].end) {
            result[*returnSize].end = intervals[i].end;
        }
    }
    (*returnSize)++;
    return result;
}

int main(int argc, char const* argv[]) {
    int a;
    merge(NULL, 0, &a);

    getchar();
    return 0;
}
