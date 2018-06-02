class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # i = -1
        # for i in range(len(nums)):
        #     if nums[i] >= target:
        #         return i
        # return i + 1

        left, right = 0, len(nums) - 1

        while left <= right:
            center = (left + right) // 2
            if nums[center] >= target:
                right = center - 1
            else:
                left = center + 1
        return left
