// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
// You are given a target value to search. If found in the array return true, otherwise return
// false.

// Example 1:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

// Follow up:
// This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// Would this affect the run-time complexity? How and why?
bool _search(int* nums, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target == nums[left] || target == nums[mid] || target == nums[right]) return 1;
        if (nums[mid] > nums[0]) {
            if (target > nums[0] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] < nums[0]) {
            if (target < nums[right] && target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            return _search(nums, left + 1, mid - 1, target) ||
                   _search(nums, mid + 1, right - 1, target);
        }
    }
    return 0;
}

bool search(int* nums, int numsSize, int target) {
    if (!nums || numsSize < 1) return 0;
    return _search(nums, 0, numsSize - 1, target);
}