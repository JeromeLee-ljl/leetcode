class Solution:
    RomanDict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        Given a roman numeral, convert it to an integer.
        Input is guaranteed to be within the range from 1 to 3999.
        """
        if s == '':
            return 0

        num = 0
        before = self.RomanDict[s[0]]
        for i in range(1, len(s)):
            current = self.RomanDict[s[i]]
            if before < current:
                num -= before
            else:
                num += before
            before = current
        num += before
        return num


def _test():
    solution = Solution()
    print(solution.romanToInt("LXXXI"))
    print(solution.romanToInt("XCIX"))


if __name__ == "__main__":
    _test()
