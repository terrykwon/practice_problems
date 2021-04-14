class Solution:

    def solveSudoku(self, board):
        print(self.solve(board, 0, 0))

        for row in board:
            print(row)

    def is_valid(self, board, row, col, val):
        # Check row for duplicate value.
        for i in range(9):
            if board[row][i] == val:
                return False

        # Check column for duplicate value.
        for i in range(9):
            if board[i][col] == val:
                return False

        # Check house for duplicate value.
        start_row = (row // 3) * 3
        start_col = (col // 3) * 3

        for i in range(3):
            for j in range(3):
                if board[start_row + i][start_col + j] == val:
                    return False

        return True

    def solve(self, board, row, col):
        """
        A solution using recursive DFS
        """
        self.print_board(board)

        if col > 8:
            row += 1
            col = 0

        if row > 8:
            return True

        if board[row][col] != '.':
            return self.solve(board, row, col + 1)

        for candidate in '123456789':
            if self.is_valid(board, row, col, candidate):
                board[row][col] = candidate

                if self.solve(board, row, col + 1):
                    return True

        board[row][col] = '.'
        return False

    def print_board(self, board):
        for row in board:
            print(row)
        print('')


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