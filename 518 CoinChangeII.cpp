class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> unique(amount + 1, 0); unique[0] = 1;

        for(const int& coin : coins) {
            for(int i = coin; i <= amount; ++i)
                unique[i] += unique[i - coin];
        }

        return unique[amount];
    }
};