class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        oldi = 0
        if len(nums) == 0: return 0
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                oldi += 1
                nums[oldi] = nums[i]

        return oldi + 1
