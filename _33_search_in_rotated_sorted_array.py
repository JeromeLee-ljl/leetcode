class Solution:
    # 全递归
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        def bin_search(nums, left, right, target):
            if nums[left] == target:
                return left
            if left == right:
                return -1

            center = (left + right) // 2
            if nums[center] == target:
                return center
            elif nums[left] > nums[center] > target:
                return bin_search(nums, left, center, target)
            elif nums[left] < nums[center] < target:
                return bin_search(nums, center + 1, right, target)
            else:
                a = bin_search(nums, left, center, target)
                return a if a != -1 else bin_search(nums, center + 1, right, target)

        if len(nums) == 0:
            return -1
        return bin_search(nums, 0, len(nums) - 1, target)

    # 半递归
    def search3(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        def bin_search(nums, left, right, target):
            while left <= right:
                if nums[left] == target:
                    return left
                if left == right:
                    return -1

                center = (left + right) // 2
                n_center = nums[center]
                n_left = nums[left]
                if n_center == target:
                    return center
                elif n_left < n_center < target or n_center < target < n_left or target < n_left < n_center:
                    # 123                           231                          312
                    left = center + 1
                elif n_center != n_left != target:
                    # 132                           321                          213
                    right = center - 1
                else:  # the case '==' can't judge, deal duplicate,though may assume no duplicate exists in the array.
                    a = bin_search(nums, left, center, target)
                    return a if a != -1 else bin_search(nums, center + 1, right, target)
            return -1

        if len(nums) == 0:
            return -1
        return bin_search(nums, 0, len(nums) - 1, target)


if __name__ == '__main__':
    # print(Solution().search3([4, 5, 6, 7, 0, 1, 2], 6))
    # print(Solution().search3([1, 1, 1, 1, 2, 3, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 3))
    # print(Solution().search([1, 2, 5], 3))
    print(Solution().search3([1], 2))
    # print(Solution().search3([1, 2, 2, 3, 4, 5], 3))
