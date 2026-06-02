class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int profit = 0;
        int n = prices.size();

        for (int i=1; i<n; i++) {
            if (prices[i] > buyPrice) {
                profit = max(profit, prices[i] - buyPrice);
            }
            else {
                buyPrice = min(buyPrice, prices[i]);
            }
        }
        
        return profit;
    }
};
