class Solution:

    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        length = len(num1) + len(num2)
        result = [0 for _ in range(length)]
        num1, num2 = list(map(int, num1)), list(map(int, num2))
        for i, a in enumerate(num1):
            for j, b in enumerate(num2):
                result[i + j + 1] += a * b
        for i in range(length - 1, -1, -1):
            if result[i] >= 10:
                result[i - 1] += result[i] // 10
                result[i] %= 10
        for i in range(length):
            if result[i] != 0:
                return ''.join([str(num) for num in result[i:]])
        return '0'


if __name__ == '__main__':
    print(Solution().multiply("123", "3"))
