class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                swap (matrix[i][j] , matrix[j][i]);
            }
        }
        for (auto &row : matrix){
            reverse(row.begin(), row.end());
        }
    }
};


// Implementation Logic:
// Convert the rows to columns: 
// i.e. Transpose the matrix (swap matrix[i][j] with matrix[j][i] for j > i):
// Reverse each row:
// (e.g., [1,2,3] -> [3,2,1]).

// Time Complexity: O(n^2) 
// Space Complexity: O(1)