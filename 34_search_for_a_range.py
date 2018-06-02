class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left, right = 0, len(nums) - 1

        while left <= right:
            center = (left + right) // 2
            if nums[center] == target:
                left_t = right_t = center
                while left < left_t:
                    center = (left + left_t) // 2
                    if nums[center] == target:
                        left_t = center
                    else:
                        left = center + 1

                while right_t < right:
                    center = (right_t + right + 1) // 2
                    if nums[center] == target:
                        right_t = center
                    else:
                        right = center - 1

                return [left_t, right_t]
            elif nums[center] < target:
                left = center + 1
            else:
                right = center - 1
        return [-1, -1]


if __name__ == '__main__':
    print(Solution().searchRange([5, 7, 7, 8, 8, 10], 8))
