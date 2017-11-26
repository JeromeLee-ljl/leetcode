class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        Write a function to find the longest common prefix string amongst an array of strings.
        """

        if len(strs) == 0:
            return ""

        min_len = len(strs[0])
        for s in strs:
            if len(s) < min_len: min_len = len(s)

        com_str = ''
        for i in range(min_len):             #并行检查
            char = strs[0][i]
            for str_i in range(len(strs)):
                if char != strs[str_i][i]:
                    return com_str
            com_str += char
        return com_str


def _test():
    solution = Solution()
    print(solution.longestCommonPrefix(["a"]))


if __name__ == "__main__":
    _test()
