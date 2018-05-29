class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        oldi = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[oldi] = nums[i]
                oldi += 1

        return oldi
