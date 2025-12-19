class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()/2;
        return nums[n];
    }
};


// Approach:
// Sort the array and return the middle element, which is the majority element.

// Time complexity = O(n log n) due to sorting;
// Space complexity = O(1);