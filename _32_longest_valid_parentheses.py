class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        results = {-1: 0}
        for i in range(len(s)):
            results[i] = 0

        is_change = True
        while is_change:
            is_change = False
            for i in list(results.keys()):
                if i not in results or i < 0: continue

                next_i = i + results[i]
                if i - 1 >= 0 and next_i < len(s):  # ( + ... + )
                    if s[i - 1] == '(' and s[next_i] == ')':
                        results[i - 1] = results[i] + 2
                        results.pop(i)
                        is_change = True

                if next_i in results:  # ... + (...)
                    results[i] += results[next_i]
                    results.pop(next_i)
                    is_change = True

        return max(results.values())

    def longestValidParentheses2(self, s):
        max_len = 0
        stack = [0]
        for char in s:

            if char == '(':
                stack.append(0)
            elif len(stack) != 1:  # ')'
                parentheses = stack.pop() + 1
                stack[-1] += parentheses
            else:
                max_len = stack[0] if stack[0] > max_len else max_len
                stack[0] = 0
            print(stack)
        return max([max_len] + stack) * 2

    def longestValidParentheses3(self, s):
        max_len = 0
        stack = [-1]
        for i in range(len(s)):
            if len(stack) != 1 and s[i] == ')' and s[stack[-1]] == '(':
                stack.pop()
                max_len = max(i - stack[-1], max_len)
            else:
                stack.append(i)
        return max_len


if __name__ == '__main__':
    # print(Solution().longestValidParentheses("((((((((((((((((((((((()()()()()()()()()()())))))))))))))))"))
    # print(Solution().longestValidParentheses2("(()))())("))
    print(Solution().longestValidParentheses3("(()))"))
