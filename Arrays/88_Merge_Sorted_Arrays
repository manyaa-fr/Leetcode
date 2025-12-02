class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

// Approach:
// 1. Copy all elements from nums2 to the end of nums1.
// 2. Sort the entire nums1 array to merge the two sorted arrays.

// Time complexity = O((m+n) log(m+n)) 
// Space complexity = O(1) 