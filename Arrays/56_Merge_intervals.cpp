class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1] , intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

// Approach:
// 1. Sort the intervals based on the starting times.
// 2. Initialize the result with the first interval.
// 3. Iterate through the sorted intervals and merge them if they overlap with the last interval in the result.
// 4. If they don't overlap, simply add the current interval to the result.

// Time complexity = O(n log n).
// Space complexity = O(n).