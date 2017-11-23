class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int

        Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
        n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
        Find two lines, which together with x-axis forms a container, such that the container contains the most water.
        Note: You may not slant the container and n is at least 2.
        """
        max = 0
        for i in range(len(height) - 1):
            for j in range(i + 1, len(height)):
                area = min(height[i], height[j]) * (j - i)
                if area > max: max = area
        return max

def _test_maxArea():
    solution = Solution()
    assert solution.maxArea([1,3,2,1])==3


if __name__ == "__main__":
    _test_maxArea()
