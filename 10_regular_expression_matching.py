class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """

        s = ' ' + s
        p = ' ' + p

        dp = [[False for col in range(len(p))] for row in range(len(s))]

        dp[0][0] = True

        for si in range(len(s)):
            for pi in range(1, len(p)):
                if si>0 and (p[pi] == '.' or p[pi] == s[si]):
                    dp[si][pi] = dp[si - 1][pi - 1]
                elif p[pi] == '*':
                    dp[si][pi] = dp[si][pi - 2]
                    if p[pi - 1] == '.' or p[pi - 1] == s[si]:
                        dp[si][pi] |= dp[si - 1][pi]

        for si in range(len(s)):
            char_s = s[si]
            for pi in range(1, len(p)):
                char_p = p[pi]
                if si > 0 and (char_p == '.' or char_p == char_s):
                    dp[si][pi] = dp[si - 1][pi - 1]
                elif char_p == '*':
                    dp[si][pi] = dp[si][pi - 2]
                    if p[pi - 1] == '.' or p[pi - 1] == s[si]:
                        dp[si][pi] |= dp[si - 1][pi]

        for d in dp:
            print(d)

        return dp[-1][-1]


if __name__ == '__main__':
    print(Solution().isMatch("", ".*."))
