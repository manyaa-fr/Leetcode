class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1, cand2 = 0;
        int count1, count2 = 0;

        for (int num : nums){
            if (num == cand1){
                count1++;
            } else if(num == cand2){
                count2++;
            } else if (count1 == 0){
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0){
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int num : nums){
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }

        vector<int> result;
        int n = nums.size();

        if(count1 > n/3) result.push_back(cand1);
        if(count2 > n/3) result.push_back(cand2);

        return result;
    }
};

// Approach:
// Use Boyer-Moore Voting Algorithm to find up to two candidates that may appear more than n/3 times.
// First pass: Identify potential candidates.
// Second pass: Verify the candidates by counting their occurrences.

// Time complexity = O(n);
// Space complexity = O(1);