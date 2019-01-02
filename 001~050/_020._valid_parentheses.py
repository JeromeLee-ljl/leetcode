class Solution:
    def isValid(self, s):
        stack = [' ']
        brackets_map = {'(': ')', '[': ']', '{': '}'}
        for char in s:
            if char in brackets_map:
                stack.append(brackets_map[char])
            elif char != stack.pop():
                return False
        return len(stack) == 1


if __name__ == '__main__':
    print(Solution().isValid('()[]'))
