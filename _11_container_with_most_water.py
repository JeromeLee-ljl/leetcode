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

        # height = list(height)
        # lenght = len(height)
        # max_height_i, max_height = 0, height[0]
        # #找最大
        # for i in range(lenght):
        #     if height[i] > max_height:
        #         max_height_i, max_height = i, height[i]
        # #转置
        # if max_height_i < lenght / 2:
        #     height.reverse()
        #     max_height_i = lenght - 1 - max_height_i
        #
        # max = 0
        # for r_i in range(max_height_i, lenght):
        #     if height[r_i] == 0: continue
        #     range_l_i = r_i - max // height[r_i]
        #     range_l_i = 0 if range_l_i < 0 else range_l_i
        #     for l_i in range(range_l_i):
        #         area = min(height[l_i], height[r_i]) * (r_i - l_i)
        #         if area > max:
        #             max = area
        # return max



        l_i, r_i = 0, len(height) - 1
        maxArea = 0
        while l_i != r_i:
            area = min(height[l_i], height[r_i]) * (r_i - l_i)
            maxArea = area if area > maxArea else maxArea
            if height[l_i] < height[r_i]:
                l_i += 1
            else:
                r_i -= 1
        return maxArea

    def maxAreaN2(self, height):
        max = 0
        for i in range(len(height) - 1):
            for j in range(i + 1, len(height)):
                area = min(height[i], height[j]) * (j - i)
                if area > max: max = area
        return max


import timeit
import numpy as np


def _test_maxArea(height):
    maxArea = Solution().maxArea
    maxAreaN2 = Solution().maxAreaN2
    glb = globals()
    glb['maxArea'] = maxArea
    glb['maxAreaN2'] = maxAreaN2
    glb['height'] = height

    t = timeit.timeit('print(maxArea(height))', number=1, globals=glb)
    tN2 = timeit.timeit('print(maxAreaN2(height))', number=1, globals=glb)
    print("1/%.2f " % (tN2 / t), t, "s", " ", tN2, "s\n")


def _tests():
    _test_maxArea(range(1, 2001))
    _test_maxArea(range(2000, 0, -1))
    _test_maxArea(np.random.randint(0, 2000, 2000))

    _test_maxArea(list(range(1, 101)) + list(range(1000, 0, -1)))
    _test_maxArea(list(range(1, 1001)) + list(range(100, 0, -1)))


if __name__ == "__main__":
    _tests()
