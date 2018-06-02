class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """

        length = len(board)
        nums = set(str(i + 1) for i in range(length))
        rows = [set() for _ in range(length)]
        cols = [set() for _ in range(length)]
        boxes = [set() for _ in range(length)]
        print('init')
        for i in range(length):
            for j in range(length):
                a = board[i][j]
                if a == '.': continue
                rows[i].add(a)
                cols[j].add(a)
                boxes[(i // 3) * 3 + j // 3].add(a)

        is_end = False
        add_random = False
        while not is_end:
            is_end = True
            # for row in board:
            #     print(row)
            for i in range(length):
                for j in range(length):
                    if board[i][j] != '.': continue
                    row, col, box = rows[i], cols[j], boxes[(i // 3) * 3 + j // 3]
                    exist = row | col | box
                    if len(exist) == 8 or (add_random and len(exist) < 8):
                        num = (nums - exist).pop()
                        board[i][j] = num
                        row.add(num)
                        col.add(num)
                        box.add(num)
                        is_end = False
                        # if len(exist) == 8:
                        #     print('fill in valid num', num)
                        if add_random:
                            add_random = False
                            print('fill in random num', num)

            if is_end and not add_random:
                add_random = True
                is_end = False
        for row in board:
            print(row)


if __name__ == '__main__':
    a = [[".", ".", ".", "2", ".", ".", ".", "6", "3"],
         ["3", ".", ".", ".", ".", "5", "4", ".", "1"],
         [".", ".", "1", ".", ".", "3", "9", "8", "."],
         [".", ".", ".", ".", ".", ".", ".", "9", "."],
         [".", ".", ".", "5", "3", "8", ".", ".", "."],
         [".", "3", ".", ".", ".", ".", ".", ".", "."],
         [".", "2", "6", "3", ".", ".", "5", ".", "."],
         ["5", ".", "3", "7", ".", ".", ".", ".", "8"],
         ["4", "7", ".", ".", ".", "1", ".", ".", "."]]
    # Solution().solveSudoku(a)


