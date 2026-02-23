class Solution {
public:

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right, vector<int>& counts){
        vector<pair<int, int>> temp;

        int i = left;
        int j = mid+1;

        int rightSmallerCount = 0;

        while (i<=mid && j<=right){
            if(arr[i].first > arr[j].first){
                temp.push_back(arr[j]);
                rightSmallerCount++;
                j++;
            } else {
                counts[arr[i].second] += rightSmallerCount;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i<=mid){
            counts[arr[i].second] += rightSmallerCount;
            temp.push_back(arr[i]);
            i++;
        }
        while (j<=right){
            temp.push_back(arr[j]);
            j++;
        }

        for (int i=0; i<temp.size(); i++){
            arr[left+i] = temp[i];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& counts){
        if (left >= right) return;
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid+1, right, counts);

        merge(arr, left, mid, right, counts);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return {0};

        vector<int> counts(n, 0);
        vector<pair<int, int>> arr;

        for (int i=0; i<n; i++){
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n-1, counts);

        return counts;
    }
};

// Approach:
// 1. Use a modified merge sort to count the number of smaller elements to the right of each element.
// 2. During the merge step, if an element from the right half is smaller than an element from the left half, it means that all remaining elements in the left half are greater than that element from the right half.
// 3. Keep track of the counts in a separate array and return it at the end.

// Time complexity = O(n log n)
// Space complexity = O(n)