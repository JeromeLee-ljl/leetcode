class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        negative = (dividend < 0) ^ (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)

        result = 0
        while dividend >= divisor:
            shift_time = 1
            while dividend >= divisor << shift_time:
                shift_time += 1
            dividend -= divisor << (shift_time - 1)
            result += 1 << (shift_time - 1)

        if negative:
            result = -result

        if (-1 << 31) <= result <= (1 << 31) - 1:
            return result
        return (1 << 31) - 1


if __name__ == '__main__':
    print(Solution().divide(-2147483648, -1))
