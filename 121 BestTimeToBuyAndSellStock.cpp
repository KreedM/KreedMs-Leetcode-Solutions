class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, smallest = prices[0];

        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] < smallest)
                smallest = prices[i];
            else
                maxP = max(maxP, prices[i] - smallest);
        }

        return maxP;
    }
};