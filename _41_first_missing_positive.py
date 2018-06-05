class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        while i < len(nums):
            pos = nums[i] - 1
            if 0 <= pos < len(nums) and nums[i] != nums[pos]:
                nums[i], nums[pos] = nums[pos], nums[i]
            else:
                i += 1
        for i in range(len(nums)):
            if nums[i] - 1 != i:
                return i + 1
        return len(nums) + 1


if __name__ == '__main__':
    print(Solution().firstMissingPositive([1, 1]))
    print(Solution().firstMissingPositive([3, 4, -1, 1]))
    print(Solution().firstMissingPositive([7, 8, 9, 11, 12]))
