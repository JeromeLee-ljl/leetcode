class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """

        if not (s and words and len(s) and len(words)): return []
        results = []
        word_len, s_len = len(words[0]), len(s)
        word_len_total = len(words) * word_len

        for i in range(word_len):
            word_map = {}
            for word in words:
                if word in word_map:
                    word_map[word] += 1
                else:
                    word_map[word] = 1

            left = right = i
            # print('##############################')
            while left < s_len - word_len_total + 1 and right < s_len:
                # print(word_map)
                # print(s)
                # print(' ' * left + s[left:right])
                # print(' ' * left + '^' + (' ' * right + '^')[left + 1:])
                # print('------------')

                left_word = s[left:left + word_len]
                right_word = s[right:right + word_len]

                if right_word in words:
                    if word_map[right_word] > 0:
                        word_map[right_word] -= 1
                        right += word_len
                    else:
                        word_map[left_word] += 1
                        left += word_len

                else:
                    while left < right:
                        word_map[left_word] += 1
                        left += word_len
                        left_word = s[left:left + word_len]

                    right += word_len
                    left += word_len

                if not any(word_map.values()):
                    results.append(left)
        return results

if __name__ == '__main__':
    print(Solution().findSubstring("aswordgoodgoodgoodbestword", ["word", "good", "best", "good"]))
