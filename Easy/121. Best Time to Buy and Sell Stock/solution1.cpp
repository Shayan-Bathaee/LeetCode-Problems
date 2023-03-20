// This solution runs in O(n) time. I'm gonna be real it looks like garbage. The idea was there but the execution was strait up bad. The program looks a lot more 
// complicated than it is, which I'm not a fan of. Check out solution 2, it's the same thing but much prettier. 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int min = prices[0];
        int max = prices[0];
        int numPrices = prices.size();

        // for every price
        for (int i = 0; i < numPrices; i++) {
            if (prices[i] < min) {              // new price we are looking at is less than our min
                if ((max - min) > maxProfit) {      // if the profit we are looking at is the best so far
                    maxProfit = max - min;          // store it
                }
                max = prices[i];                // set max and min equal
                min = prices[i];
            }
            if (prices[i] > max) {              // new price we are looking at is greater than our max
                max = prices[i];
            }
        }

        if ((max - min) > maxProfit) {          // check if the final max/min difference is greatest
            maxProfit = max - min;
        }

        return maxProfit;
    }

};