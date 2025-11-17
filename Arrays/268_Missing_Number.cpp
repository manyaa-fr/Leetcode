// Brute force approach:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i=0; i<=nums.size(); i++){
            bool contain = false;
            for (int j=0; j<nums.size(); j++){
                if (i == nums[j]){
                    contain = true;
                    break;
                }
            }
            if (!contain){
                return i;
            }
        }
        return 0;
    }
};

// Optimized Approach:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int numsum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += i;
            numsum += nums[i];
        }
        sum += nums.size();
        return sum - numsum;
    }
};

// Implementation Logic

// Initialize two sums:
// sum = cumulative expected sum (0 to n-1 during loop).
// numsum = cumulative actual array sum.
// After loop, add nums.size() (i.e., n) to sum to complete the expected sequence (0 to n).
// Return sum - numsum.