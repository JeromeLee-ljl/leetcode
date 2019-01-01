class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        string = '1 '
        for _ in range(1, n):
            temp = ''
            count = 1
            for j in range(1, len(string)):
                if string[j] == string[j - 1]:
                    count += 1
                else:
                    temp += str(count) + string[j - 1]
                    count = 1
            string = temp + ' '
        return string[0:-1]

    def countAndSay2(self, n):
        """
        :type n: int
        :rtype: str
        """
        string = '1 '
        for _ in range(1, n):
            tmp = []
            count = 1
            for j in range(1, len(string)):
                if string[j] == string[j - 1]:
                    count += 1
                else:
                    tmp.append(str(count))
                    tmp.append(string[j - 1])
                    count = 1
            string = ''.join(tmp+' ')
        return string[0:-1]

if __name__ == '__main__':
    print(Solution().countAndSay(4))
    # print(Solution().countAndSay2(50))
