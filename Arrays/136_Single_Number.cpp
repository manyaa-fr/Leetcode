// XOR Approach:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for (int num : nums){
            n ^= num;
        }
        return n;
    }
};

// Implementation Logic:

// Initialize n = 0
// Iterate through each number in nums
// For each num, update n = n XOR num.
// Return n