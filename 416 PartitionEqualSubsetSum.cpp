class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(const int& num : nums)
            sum += num;
        if(sum % 2)
            return false;
        sum >>= 1;

        vector<bool> knapsack(sum + 1, false); knapsack[0] = true;
        for(const int& num : nums) {
            for(int i = sum; i >= num; --i)
                knapsack[i] = knapsack[i] || knapsack[i - num];
        }

        return knapsack[sum];
    }
};