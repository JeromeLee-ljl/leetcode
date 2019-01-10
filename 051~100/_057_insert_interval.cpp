// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if
// necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

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

int compare_interval(struct Interval a, struct Interval b) { return a.start - b.start; }
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval,
                        int* returnSize) {
    *returnSize = 0;
    if (intervalsSize < 0) return NULL;

    struct Interval* result =
        (struct Interval*)malloc(sizeof(struct Interval) * (intervalsSize + 1));

    int i = 0;
    for (; i < intervalsSize && newInterval.start > intervals[i].end; i++) {  // left
        result[*returnSize].start = intervals[i].start;
        result[(*returnSize)++].end = intervals[i].end;
    }
    if (i == intervalsSize) {
        result[*returnSize].start = newInterval.start;
        result[(*returnSize)++].end = newInterval.end;
        return result;
    }

    result[*returnSize].start = min(intervals[i].start, newInterval.start);  // mid
    for (; i < intervalsSize && newInterval.end > intervals[i].end; i++) {
        continue;
    }
    if (i == intervalsSize) {
        result[(*returnSize)++].end = newInterval.end;
        return result;
    }
    if (newInterval.end < intervals[i].start) {
        result[(*returnSize)++].end = newInterval.end;
    } else {
        result[(*returnSize)++].end = intervals[i++].end;
    }

    for (; i < intervalsSize; i++) {  // right
        result[*returnSize].start = intervals[i].start;
        result[(*returnSize)++].end = intervals[i].end;
    }
    return result;
}

struct Interval* insert2(struct Interval* intervals, int intervalsSize, struct Interval newInterval,
                         int* returnSize) {
    *returnSize = 0;
    if (intervalsSize < 0) return NULL;

    struct Interval* result = (struct Interval*)malloc(sizeof(struct Interval) * (intervalsSize + 1));

    int i = 0;
    for (; i < intervalsSize && newInterval.start > intervals[i].end; i++) {    // left
        result[*returnSize].start = intervals[i].start;
        result[(*returnSize)++].end = intervals[i].end;
    }

    for (; i < intervalsSize && newInterval.end >= intervals[i].start; i++) {      // mid
        newInterval.start = min(intervals[i].start, newInterval.start);  
        newInterval.end = max(intervals[i].end,newInterval.end);
    }
    result[*returnSize].start = newInterval.start;
    result[(*returnSize)++].end = newInterval.end;

    for (; i < intervalsSize; i++) {  // right
        result[*returnSize].start = intervals[i].start;
        result[(*returnSize)++].end = intervals[i].end;
    }

    return result;
}
