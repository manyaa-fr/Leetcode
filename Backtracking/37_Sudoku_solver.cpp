class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') { // Empty cell
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) { // Check validity
                            board[i][j] = c;
                            if (solve(board)) return true; // Recurse
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid digit found
                }
            }
        }
        return true; // No empty cells → solved!
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // Check row
        for (int i = 0; i < 9; i++) 
            if (board[row][i] == c) return false;
        
        // Check column
        for (int i = 0; i < 9; i++) 
            if (board[i][col] == c) return false;
        
        // Check 3x3 box
        int boxRow = row - row % 3, boxCol = col - col % 3;
        for (int i = 0; i < 3; i++) 
            for (int j = 0; j < 3; j++) 
                if (board[boxRow + i][boxCol + j] == c) 
                    return false;
        
        return true;
    }
};

// Approach:
// Use backtracking to fill the Sudoku board.
// For each empty cell, try digits '1' to '9' and check if placing the digit is valid.
// If valid, place the digit and recursively attempt to solve the rest of the board.
// If placing the digit leads to a solution, return true.
// If not, backtrack by resetting the cell and trying the next digit.

// Time complexity = O(9^(n*n)) in the worst case, where n is the size of the board (9).
// Space complexity = O(1) as we are modifying the board in place.