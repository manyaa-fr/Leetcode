class Solution {
public:
    
    void backtrack(vector<string>& board, int row, vector<int>& cols, vector<int>& diag1, vector<int>& diag2,vector<vector<string>>& result){
        int n = board.size();
        if (row == n){
            result.push_back(board);
            return;
        }

        for (int col=0; col<n; col++){
            if (cols[col] || diag1[row-col+n-1] || diag2[row+col]){
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = diag1[row-col+n-1] = diag2[row+col] = 1;
            backtrack (board, row+1, cols, diag1, diag2, result);
            board[row][col] = '.';
            cols[col] = diag1[row-col+n-1] = diag2[row+col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
     vector<string> board(n, string(n, '.'));
     vector<int> cols(n, 0);
     vector<int> diag1(2*n-1, 0);
     vector<int> diag2(2*n-1, 0);
     vector<vector<string>> result;
     backtrack(board, 0, cols, diag1, diag2, result);
     return result;   
    }
};

// Approach: Backtracking
// Time Complexity: O(N!)
// Space Complexity: O(N^2)