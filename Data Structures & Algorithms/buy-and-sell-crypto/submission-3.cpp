class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        if (prices.size() == 1) return 0;
        int profit = 0;

        for (auto price: prices) {
            profit = max(profit, price - buyPrice);
            buyPrice = min(buyPrice, price);
        }

        return profit;
    }
};
