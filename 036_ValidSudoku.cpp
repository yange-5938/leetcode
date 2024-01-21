// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 

// Example 1:


// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (const auto& row : board) {
            if (!isValidGroup(row)) return false;
        }

        for (size_t j =0; j<9; ++j){
            std::vector<char> column;
            for (size_t i =0;i<9;++i){
                column.push_back(board[i][j]);
            }
            if(!isValidGroup(column)) return false;
        }

        for (size_t i = 0; i < 9; i += 3) {
            for (size_t j = 0; j < 9; j += 3) {
                std::vector<char> sub_board;
                for (size_t x = i; x < i + 3; ++x) {
                    for (size_t y = j; y < j + 3; ++y) {
                        sub_board.push_back(board[x][y]);
                    }
                }
                if (!isValidGroup(sub_board)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isValidGroup(const std::vector<char>& group) {
        std::unordered_set<char> seen;
        for(char num : group){
            if (num != '.'){
                if (seen.find(num) != seen.end()){
                    return false;
                }
                seen.insert(num);
            }
        }
        return true;
    }
};
