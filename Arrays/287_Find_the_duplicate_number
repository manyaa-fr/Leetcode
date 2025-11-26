class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return 0;
    }
};
// Approach:
// Sort the array and check for consecutive duplicate elements.

// Time complexity = O(n log n) due to sorting;
// Space complexity = O(1);



// # OPTIMIZED SOLUTION
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for( int num : nums){
            int idx = abs(num);
            if (nums[idx] < 0){
                return idx;
            }
            nums[idx] *= -1;
        }

        return -1;
    }
};
// Approach:
// Use the input array itself to track visited numbers by negating the value at the index corresponding to each number.
// If we encounter a negative value at that index, it indicates the number has been seen before.

// Time complexity = O(n);
// Space complexity = O(1);