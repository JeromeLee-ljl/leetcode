class Solution:
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: float

    There are two sorted arrays nums1 and nums2 of size m and n respectively.
    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    Example 1:
    nums1 = [1, 3]
    nums2 = [2]
    The median is 2.0

    Example 2:
    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5
    """

    def findMedianSortedArrays(self, nums1, nums2):
        l1, l2 = len(nums1), len(nums2)
        if l1 > l2:
            l1, l2, nums1, nums2 = l2, l1, nums2, nums1
        if l2 == 0:
            raise ValueError

        left, right = 0, l1
        while left <= right:
            cut1 = (left + right) // 2
            cut2 = (l1 + l2) // 2 - cut1

            if cut1 > 0 and nums1[cut1 - 1] > nums2[cut2]:
                # cut1太大
                right = cut1 - 1
            elif cut1 < l1 and nums2[cut2 - 1] > nums1[cut1]:
                # cut1太小
                left = cut1 + 1
            else:
                # 找到
                if cut1 == l1:
                    min_right = nums2[cut2]
                elif cut2 == l2:
                    min_right = nums1[cut1]
                else:
                    min_right = min(nums1[cut1], nums2[cut2])
                if (l1 + l2) % 2 == 1:
                    # 奇数个
                    return min_right

                # 偶数个
                if cut1 == 0:
                    max_left = nums2[cut2 - 1]
                elif cut2 == 0:
                    max_left = nums1[cut1 - 1]
                else:
                    max_left = max(nums1[cut1 - 1], nums2[cut2 - 1])

                return (max_left + min_right) / 2
        raise ValueError


def _test_solution():
    solution = Solution()
    assert solution.findMedianSortedArrays([1, 3],[2]) == 2, "([1,3], [2]) == 2"
    assert solution.findMedianSortedArrays([1, 2], [3, 4]) == 2.5, "([1,2], [3,4]) == 2.5"
    assert solution.findMedianSortedArrays([], [2,3]) == 2.5, "([], [2,3]) == 2.5"


if __name__ == '__main__':
    _test_solution()
