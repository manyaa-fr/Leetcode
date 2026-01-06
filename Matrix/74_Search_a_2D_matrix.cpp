// Brute force approach: O(m * n) time complexity
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};

// Implementation Logic: The function iterates through each element of the 2D matrix using nested loops. If it finds an element equal to the target, it returns true. If it completes the search without finding the target, it returns false.



// Optimized approach: O(log(m * n)) time complexity using binary search:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = matrix[mid / n][mid % n];
            
            if (val == target) return true;
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

// Implementation Logic: 

// Virtual 1D Array:
// Matrix size = m*n ; 1D array size = m*n.
// Element at index k = matrix[k/n][k%n].

// Binary Search:
// low = 0, high = m*n - 1.
// For each mid, compute matrix[mid/n][mid%n] and compare with target.