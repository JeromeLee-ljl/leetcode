class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]

        Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
        A solution set is:
        [
          [-1,  0, 0, 1],
          [-2, -1, 1, 2],
          [-2,  0, 0, 2]
        ]
        """


        def n_sum(nums, target, n, start, head_result, results):
            if len(nums) - start < n or not (nums[start] <= target / n <= nums[-1]):
                return
            if n == 2:
                left, right = start, len(nums) - 1
                while left < right:
                    sum = nums[left] + nums[right]
                    if sum == target:
                        print('left',left,nums[left],'right',right, nums[right])
                        results.append(head_result + [nums[left], nums[right]])
                    if sum <= target:

                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        left += 1
                    else:
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        right -= 1
            else:
                for i in range(start, len(nums) - n + 1):
                    if i > start and nums[i] == nums[i - 1]: continue
                    n_sum(nums, target - nums[i], n - 1, i + 1, head_result + [nums[i]], results)

        results = []
        nums.sort()
        n_sum(nums, target, 4, 0, [], results)
        return results


if __name__ == '__main__':
    print('result',Solution().fourSum([-3,-2,-1,0,0,1,2,3], 0))
