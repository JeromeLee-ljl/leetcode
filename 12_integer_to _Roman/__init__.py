class Solution:
    Roman = ('I', 'V', 'X', 'L', 'C', 'D', 'M')

    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        Given an integer, convert it to a roman numeral.
        Input is guaranteed to be within the range from 1 to 3999.
        """
        if num > 3999:
            raise ValueError

        decimals = []
        roman_str = ''

        while num != 0:
            n = num % 10
            num //= 10
            decimals.append(n)

        for i in range(len(decimals) * 2 - 1, 0, -2):
            n = decimals[i // 2]
            if n < 5:
                if n < 4:
                    roman_str += self.Roman[i - 1] * n
                else:
                    roman_str += self.Roman[i - 1] + self.Roman[i]
            else:
                n -= 5
                if n < 4:
                    roman_str += self.Roman[i] + self.Roman[i - 1] * n
                else:
                    roman_str += self.Roman[i - 1] + self.Roman[i + 1]
        return roman_str


def _test():
    solution = Solution()
    print(solution.intToRoman(3))
    print(solution.intToRoman(4))
    print(solution.intToRoman(25))
    print(solution.intToRoman(81))


if __name__ == "__main__":
    _test()
