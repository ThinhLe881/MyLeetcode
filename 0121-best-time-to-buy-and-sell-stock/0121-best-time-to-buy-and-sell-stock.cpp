class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0], profit = 0;

        for (int price : prices) {
            if (price < buy_price) {
                buy_price = price;
            } else if (price - buy_price > profit) {
                profit = price - buy_price;
            }
        }

        return profit;
    }
};