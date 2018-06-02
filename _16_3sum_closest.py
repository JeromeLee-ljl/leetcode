class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int

        Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
        Return the sum of the three integers.
        You may assume that each input would have exactly one solution.

        For example, given array S = {-1 2 1 -4}, and target = 1.
        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
        """
        nums.sort()
        closest = None
        min_diff = None
        for l_i in range(len(nums) - 2):
            if l_i != 0 and nums[l_i] == nums[l_i - 1]: continue
            c_i, r_i = l_i + 1, len(nums) - 1
            while c_i < r_i:
                sum = nums[l_i] + nums[c_i] + nums[r_i]
                if sum < target:
                    c_i += 1
                elif sum > target:
                    r_i -= 1
                else:
                    return target

                diff = abs(sum - target)
                if min_diff is None or diff < min_diff:
                    min_diff = diff
                    closest = sum
        return closest
