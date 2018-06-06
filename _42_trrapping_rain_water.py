class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        if not height or len(height) == 0: return 0
        trap = 0
        height_index_stack = [0]
        for right_i in range(1, len(height)):
            right = height[right_i]
            while right >= height[height_index_stack[-1]]:
                mid = height[height_index_stack.pop()]
                if len(height_index_stack) == 0: break
                left_i = height_index_stack[-1]
                left = height[left_i]
                trap += (right_i - left_i - 1) * (min(left, right) - mid)
            height_index_stack.append(right_i)
        return trap

    def trap2(self, height):
        if not height or len(height) == 0: return 0

        level = left = trap = 0
        right = len(height) - 1
        while left < right:
            lower = min(height[left], height[right])
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

            level = max(level, lower)
            trap += level - lower
        return trap


if __name__ == '__main__':
    print(Solution().trap2([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
