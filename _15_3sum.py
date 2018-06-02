class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
        Find all unique triplets in the array which gives the sum of zero.

        Note: The solution set must not contain duplicate triplets.
        For example, given array S = [-1, 0, 1, 2, -1, -4],
        A solution set is:
        [
            [-1, 0, 1],
            [-1, -1, 2]
        ]
        """
        nums.sort()
        solutions = []

        for l_i in range(len(nums)):
            if l_i != 0 and nums[l_i] == nums[l_i - 1]: continue
            c_i, r_i = l_i + 1, len(nums) - 1
            while c_i < r_i:
                sum = nums[l_i] + nums[c_i] + nums[r_i]
                if sum < 0:
                    c_i += 1
                elif sum > 0:
                    r_i -= 1
                else:
                    solutions.append([nums[l_i], nums[c_i], nums[r_i]])
                    while c_i < r_i and nums[c_i] == nums[c_i + 1]:
                        c_i += 1
                    while c_i < r_i and nums[r_i] == nums[r_i - 1]:
                        r_i -= 1
                    c_i += 1
                    r_i -= 1
        return solutions


import numpy as np
import timeit


def _test():
    solution = Solution()
    glob = globals()
    glob['solution'] = solution

    print(solution.threeSum([-1, 0, 1, 2, -1, -4]))
    print(solution.threeSum([0, 0, 0, 0]))

    t = timeit.timeit('print(solution.threeSum(np.random.randint(-1000,1000,1000)))', number=1, globals=glob)
    print(t)


if __name__ == "__main__":
    _test()
