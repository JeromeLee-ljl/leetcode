class Solution:
    def show(self, board, info='result'):

        print(info)
        print(' -------------------------')
        for i in range(len(board)):
            s = ''
            for j in range(len(board)):
                if j % 3 == 0:
                    s = ' '.join([s, '|', board[i][j]])
                else:
                    s = ' '.join([s, board[i][j]])
            print(s + ' |')
            if (i + 1) % 3 == 0:
                print(' -------------------------')

    def solveSudoku(self, board):
        length = len(board)
        nums = set('123456789')
        cols = [set() for _ in range(length)]
        boxes = [set() for _ in range(length)]
        nums_locs = [set() for _ in range(length)]  # (i,j)
        for row_i in range(length):
            for col_i in range(length):
                num = board[row_i][col_i]
                if num == '.': continue
                cols[col_i].add(num)
                boxes[row_i // 3 * 3 + col_i // 3].add(num)
                nums_locs[int(num) - 1].add((row_i, col_i))

        # Hidden Single
        def solve_hidden():
            is_end = True
            for n_i in range(length):  # traversal number
                num = str(n_i + 1)
                locs = nums_locs[n_i]
                exist_row = set([loc[0] for loc in locs])
                exist_col = set([loc[1] for loc in locs])
                for b_i in range(length):
                    if num not in boxes[b_i]:  # Hidden Single
                        row_start = b_i // 3 * 3
                        col_start = b_i % 3 * 3
                        row = set(range(row_start, row_start + 3)) - exist_row
                        col = set(range(col_start, col_start + 3)) - exist_col
                        count = first_row_i = first_col_i = 0
                        for row_i in row:
                            for col_i in col:
                                if board[row_i][col_i] == '.':
                                    count += 1
                                    if count == 1:
                                        first_row_i = row_i
                                        first_col_i = col_i
                                    else:
                                        break
                            else:
                                continue
                            break
                        if count == 1:
                            # print(f'Hidden Single add {num} to {first_row_i,first_col_i}')
                            board[first_row_i][first_col_i] = num
                            cols[first_col_i].add(num)
                            boxes[b_i].add(num)
                            nums_locs[n_i].add((first_row_i, first_col_i))
                            is_end = False

            if not is_end:
                solve_hidden()

        def solve_force(i):
            row_i, col_i = i // 9, i % 9
            while board[row_i][col_i] != '.':
                if i == 80: return True  # all filled
                i += 1
                row_i, col_i = i // 9, i % 9

            col, box = cols[col_i], boxes[(row_i // 3) * 3 + col_i // 3]
            candidate = nums - (set(board[row_i]) | col | box)

            for num in candidate:
                # print(f'attempt add {num} to {row_i,col_i}')
                board[row_i][col_i] = num
                col.add(num)
                box.add(num)
                if solve_force(i): return True
                # print(f'remove {num} from {row_i,col_i}')
                board[row_i][col_i] = '.'
                col.remove(num)
                box.remove(num)
            return False

        solve_hidden()
        solve_force(0)
        self.show(board)


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
    b = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
         ["6", ".", ".", "1", "9", "5", ".", ".", "."],
         [".", "9", "8", ".", ".", ".", ".", "6", "."],
         ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
         ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
         ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
         [".", "6", ".", ".", ".", ".", "2", "8", "."],
         [".", ".", ".", "4", "1", "9", ".", ".", "5"],
         [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    c = [['.', '.', '9', '7', '4', '8', '.', '.', '.'],
         ['7', '.', '.', '.', '.', '.', '.', '.', '.'],
         ['.', '2', '.', '1', '.', '9', '.', '.', '.'],
         ['.', '.', '7', '.', '.', '.', '2', '4', '.'],
         ['.', '6', '4', '.', '1', '.', '5', '9', '.'],
         ['.', '9', '8', '.', '.', '.', '3', '.', '.'],
         ['.', '.', '.', '8', '.', '3', '.', '2', '.'],
         ['.', '.', '.', '.', '.', '.', '.', '.', '6'],
         ['.', '.', '.', '2', '7', '5', '9', '.', '.']]

    Solution().solveSudoku(a)

    import _036_valid_sudoku

    print(_036_valid_sudoku.Solution().isValidSudoku(a))

    # from timeit import timeit
    #
    # number = 1000
    # import_str = 'from __main__ import Solution,a'
    #
    # a = [[".", ".", ".", "2", ".", ".", ".", "6", "3"],
    #      ["3", ".", ".", ".", ".", "5", "4", ".", "1"],
    #      [".", ".", "1", ".", ".", "3", "9", "8", "."],
    #      [".", ".", ".", ".", ".", ".", ".", "9", "."],
    #      [".", ".", ".", "5", "3", "8", ".", ".", "."],
    #      [".", "3", ".", ".", ".", ".", ".", ".", "."],
    #      [".", "2", "6", "3", ".", ".", "5", ".", "."],
    #      ["5", ".", "3", "7", ".", ".", ".", ".", "8"],
    #      ["4", "7", ".", ".", ".", "1", ".", ".", "."]]
    # print('combine', timeit('Solution().solveSudoku(a)', import_str, number=number)*1000)
    #
    # a = [[".", ".", ".", "2", ".", ".", ".", "6", "3"],
    #      ["3", ".", ".", ".", ".", "5", "4", ".", "1"],
    #      [".", ".", "1", ".", ".", "3", "9", "8", "."],
    #      [".", ".", ".", ".", ".", ".", ".", "9", "."],
    #      [".", ".", ".", "5", "3", "8", ".", ".", "."],
    #      [".", "3", ".", ".", ".", ".", ".", ".", "."],
    #      [".", "2", "6", "3", ".", ".", "5", ".", "."],
    #      ["5", ".", "3", "7", ".", ".", ".", ".", "8"],
    #      ["4", "7", ".", ".", ".", "1", ".", ".", "."]]
    # print('hidden ', timeit('Solution().solveSudoku2(a)', import_str, number=number)*1000)
    #
    # a = [[".", ".", ".", "2", ".", ".", ".", "6", "3"],
    #      ["3", ".", ".", ".", ".", "5", "4", ".", "1"],
    #      [".", ".", "1", ".", ".", "3", "9", "8", "."],
    #      [".", ".", ".", ".", ".", ".", ".", "9", "."],
    #      [".", ".", ".", "5", "3", "8", ".", ".", "."],
    #      [".", "3", ".", ".", ".", ".", ".", ".", "."],
    #      [".", "2", "6", "3", ".", ".", "5", ".", "."],
    #      ["5", ".", "3", "7", ".", ".", ".", ".", "8"],
    #      ["4", "7", ".", ".", ".", "1", ".", ".", "."]]
    # print('force  ', timeit('Solution().solveSudoku3(a)', import_str, number=number)*1000)
