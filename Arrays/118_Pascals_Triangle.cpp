class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);

        for (int i=0; i<numRows; i++){
            result[i].resize(i+1);
            result[i][0] = result[i][i] = 1;

            for (int j=1; j<i; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }

        return result;
    }
};


// Approach:
// Initialize boundaries: First and last elements of each row = 1.
// Build row by row using the recurrence:
// result[i][j] = result[i-1][j-1] + result[i-1][j] (for 0 < j < i).

// Time complexity = O(n^2);
// Space complexity = O(n^2);