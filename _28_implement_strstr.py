class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0: return 0

        for hi in range(len(haystack)-len(needle)+1):
            for ni in range(len(needle)):
                if haystack[hi + ni] != needle[ni]:
                    break
                if ni == len(needle) - 1:
                    return hi
        return -1
