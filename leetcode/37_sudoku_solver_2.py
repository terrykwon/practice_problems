class Solution:

    # @param board, a 9x9 2D array
    # Solve the Sudoku by modifying the input board in-place.
    # Do not return any value.
    def check(self, x, y, board):
        temp = board[x][y]
        board[x][y] = '.'
        for row in range(9):
            if board[row][y] == temp:
                return False
        for col in range(9):
            if board[x][col] == temp:
                return False
        for row in range(3):
            for col in range(3):
                if board[(x // 3) * 3 + row][(y // 3) * 3 + col] == temp:
                    return False
        board[x][y] = temp
        return True

    def dfs(self, board):
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    for char in '123456789':
                        board[row][col] = char
                        if self.check(row, col, board) and self.dfs(board):
                            return True
                        board[row][col] = '.'
                    return False
        return True

    def solveSudoku(self, board):
        self.dfs(board)
        for row in board:
            print(row)


board = ["..9748...",
         "7........",
         ".2.1.9...",
         "..7...24.",
         ".64.1.59.",
         ".98...3..",
         "...8.3.2.",
         "........6",
         "...2759.."]

solution = ["519748632",
            "783652419",
            "426139875",
            "357986241",
            "264317598",
            "198524367",
            "975863124",
            "832491756",
            "641275983"]

b = list(map(list, board))
sol = Solution()
sol.solveSudoku(b)
