class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        phone_button = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        if  len(digits) == 0:
            return []
        elif len(digits) == 1:
            return [char for char in phone_button[digits]]
        else:
            combinations_before = self.letterCombinations(digits[0:-1])

            combinations_after = []
            for combination in combinations_before:
                for char in phone_button[digits[-1]]:
                    combinations_after.append(combination + char)

            return combinations_after
