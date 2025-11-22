class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] > 0){
                positives.push_back(nums[i]);
            }
            else if (nums[i] < 0){
                negatives.push_back(nums[i]);
            }
        }
        vector<int>newnums;
        for (int i=0; i<nums.size()/2; i++){
            newnums.push_back(positives[i]); 
            newnums.push_back(negatives[i]); 
        }

        return newnums;
    }
};

// Approach:
// Separate positive and negative numbers into two lists.
// Then, merge them by alternating elements from each list.
// Time Complexity: O(n)
// Space Complexity: O(n)