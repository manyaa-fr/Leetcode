class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i=0; i<nums.size() - 2; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = nums.size()-1;

            while (left < right){
                int sum = nums[i] + nums[right] + nums[left];

                if (sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left] ==nums[left+1]) left++;
                    while(left<right && nums[right] ==nums[right-1]) right--;
                    left++;
                    right--;
                } else if (sum < 0){
                    left++;
                } else{
                    right--;
                }
            }
        }
        return result;
    }
};


// Approach:
// 1. Sort the input array.
// 2. Iterate through the array, fixing one element and using two pointers to find pairs that sum to the negative of the fixed element.
// 3. Skip duplicates to ensure unique triplets in the result.
// 4. Use a while loop with two pointers to find pairs that sum to the negative of the fixed element.

// Time complexity = O(n^2);
// Space complexity = O(1);