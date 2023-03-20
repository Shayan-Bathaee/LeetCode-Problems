// This solution runs in O(n) time and has O(1) space complexity. It works by iterating through the prices, keeping track of the minimum price, and checking if we can
// make more profit at each step by calculating the difference between our current price and the previous minimum. At the end, it returns the maximum it found. 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        int numPrices = prices.size();

        // for every price
        for (int i = 0; i < numPrices; i++) {
            minPrice = min(minPrice, prices[i]); // reset minPrice if this one is less
            maxProfit = max(maxProfit, prices[i] - minPrice); // reset maxProfit if we can make more at this price
        }

        return maxProfit;
    }

};