class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i=0; i<prices.size(); i++){
            if (prices[i] < buy){
                buy = prices[i];
            } else if (prices[i] - buy > profit){
                profit = prices[i]-buy;
            }
        }
        return profit;
    }
};

// Approach:
// Track the lowest price.
// For each price, calculate profit as (current price - lowest price).
// Update the maximum profit whenever a higher profit is found.

// Time Complexity: O(n) 
// Space Complexity: O(1)