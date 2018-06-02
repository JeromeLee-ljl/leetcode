class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        def generate(head, left_n, right_n, results):
            print(left_n,right_n)
            if left_n > 0:
                generate(head + '(', left_n - 1, right_n, results)
            if right_n > left_n:
                generate(head + ')', left_n, right_n - 1, results)
            if right_n == 0:
                results.append(head)

        results = []
        generate('', n, n, results)
        return results


if __name__ == '__main__':
    print(Solution().generateParenthesis(3))
