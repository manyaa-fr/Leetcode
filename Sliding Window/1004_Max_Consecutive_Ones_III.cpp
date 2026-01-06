class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size();
        int count = 0;
        int maxLen = 0;

        for (int i = left; i<right; i++){
            if (nums[i] == 0) count++;

            while(count > k){
                if (nums[left] == 0){
                    count--;
                }
                left++;
            }

            maxLen = max(maxLen, i-left+1);
        }

         return maxLen;
    }
};

// Approach:
// Use a sliding window approach to find the longest subarray with at most k zeros.
// Expand the window by moving the right pointer and count zeros.
// If the count of zeros exceeds k, shrink the window from the left until the count is within the limit.

// Time complexity = O(n);
// Space complexity = O(1);