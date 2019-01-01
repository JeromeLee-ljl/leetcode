class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        def solve(candidates, target, start, head):
            results = []
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:continue
                num = candidates[i]
                if num < target:
                    results += solve(candidates, target - num, i + 1, head + [num])
                else:
                    if num == target:
                        results.append(head + [num])
                    return results
            return results

        candidates.sort()
        return solve(candidates, target, 0, [])


if __name__ == '__main__':
    print(Solution().combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
