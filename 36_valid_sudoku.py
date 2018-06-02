class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        length = len(board)

        for i in range(length):
            row = set()
            col = set()
            for j in range(length):
                a = board[i][j]
                b = board[j][i]
                if a in row or b in col: return False
                if a != '.': row.add(a)
                if b != '.': col.add(b)

        for i in range(0, length, 3):
            for j in range(0, length, 3):
                sets = set()
                for i2 in range(3):
                    for j2 in range(3):
                        a = board[i + i2][j + j2]
                        if a in sets: return False
                        if a != '.': sets.add(a)
        return True

    def isValidSudoku2(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        length = len(board)
        rows = [set() for _ in range(length)]
        cols = [set() for _ in range(length)]
        boxes = [set() for _ in range(length)]
        for i in range(length):
            for j in range(length):
                a = board[i][j]
                if a == '.': continue
                row = rows[i]
                col = cols[j]
                box = boxes[(i // 3) * 3 + j // 3]
                if a in row or a in col or a in box: return False
                row.add(a)
                col.add(a)
                box.add(a)
        return True


if __name__ == '__main__':
    a = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
         ["6", ".", ".", "1", "9", "5", ".", ".", "."],
         [".", "9", "8", ".", ".", ".", ".", "6", "."],
         ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
         ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
         ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
         [".", "6", ".", ".", ".", ".", "2", "8", "."],
         [".", ".", ".", "4", "1", "9", ".", ".", "5"],
         [".", ".", ".", ".", "8", ".", ".", "7", "9"]]

    print(Solution().isValidSudoku2(a))

    b = [[".", ".", ".", ".", "5", ".", ".", "1", "."],
         [".", "4", ".", "3", ".", ".", ".", ".", "."],
         [".", ".", ".", ".", ".", "3", ".", ".", "1"],
         ["8", ".", ".", ".", ".", ".", ".", "2", "."],
         [".", ".", "2", ".", "7", ".", ".", ".", "."],
         [".", "1", "5", ".", ".", ".", ".", ".", "."],
         [".", ".", ".", ".", ".", "2", ".", ".", "."],
         [".", "2", ".", "9", ".", ".", ".", ".", "."],
         [".", ".", "4", ".", ".", ".", ".", ".", "."]]
    # print(Solution().isValidSudoku2(b))
