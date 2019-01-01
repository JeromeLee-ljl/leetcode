class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0:
            if nums[i] < nums[i + 1]:
                left, right = i + 1, len(nums) - 1
                while left < right - 1:
                    center = (left + right) // 2
                    mid = nums[center]
                    if nums[i] >= mid:
                        right = center
                    else:
                        left = center
                if nums[i] >= nums[right]:
                    right -= 1
                nums[i], nums[right] = nums[right], nums[i]
                break
            i -= 1
        #
        # for i in range(len(nums) - 2, -2, -1):
        #     if i >= 0 and nums[i] < nums[i + 1]:
        #         left, right = i + 1, len(nums) - 1
        #         while left < right - 1:
        #             center = (left + right) // 2
        #             mid = nums[center]
        #             if nums[i] >= mid:
        #                 right = center
        #             else:
        #                 left = center
        #         if nums[i] >= nums[right]:
        #             right -= 1
        #         nums[i], nums[right] = nums[right], nums[i]
        #         break

        left, right = i + 1, len(nums) - 1
        while left < right:
            nums[right], nums[left] = nums[left], nums[right]
            left += 1
            right -= 1

        print(nums)


if __name__ == '__main__':
    Solution().nextPermutation([3, 2, 1])
