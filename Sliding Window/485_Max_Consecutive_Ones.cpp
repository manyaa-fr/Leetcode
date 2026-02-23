class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0;
        int currNum = 0;
        for (int i=1 ; i<=nums.size() ; i++){
            if (nums[i-1] == 1){
                currNum++;
                maxNum = max(maxNum, currNum);
            } else {
                currNum=0;
            }
        }
        return maxNum;
    }
};


// ### Approach
// - Iterate through the array once,
// - maintain a running count of consecutive 1s 
// - update the maximum when a 1 is encountered. 
// - Reset the running count when a 0 is seen.