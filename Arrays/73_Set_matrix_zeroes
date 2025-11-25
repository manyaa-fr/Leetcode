class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == 0){
                    col[j] = 1;
                    row[i] = 1;
                }
            }
        }
        for (int i=0; i< matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (col[j] == 1 || row[i] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// Approach:
// Use two arrays to mark rows and columns that need to be zeroed.
// First pass: Identify all rows and columns that contain zero.
// Second pass: Set matrix elements to zero if their row or column is marked.

// Time complexity = O(m*n);
// Space complexity = O(m + n);