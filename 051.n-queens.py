# The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

# Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

# Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

# Example 1:


# Input: n = 4
# Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
# Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
# Example 2:

# Input: n = 1
# Output: [["Q"]]
 

# Constraints:

# 1 <= n <= 9

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def createBoard(state):
            board = []
            for row in state:
                board.append("".join(row))
            return board

        def isValid(board, row, col):
            # Check column
            for i in range(row):
                if board[i][col] == 'Q':
                    return False
            # Check diagonal (top-left to bottom-right)
            i, j = row, col
            while i >= 0 and j >= 0:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1
            # Check anti-diagonal (top-right to bottom-left)
            i, j = row, col
            while i >= 0 and j < n:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j += 1
            return True

        def solve(row):
            if row == n:
                result.append(createBoard(board))
                return
            
            for col in range(n):
                if isValid(board, row, col):
                    board[row][col] = 'Q'
                    solve(row + 1)
                    board[row][col] = '.'

        result = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        solve(0)
        return result
