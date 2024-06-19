class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();

        int maxSum = nums[0], sum = nums[0];

        for(int i = 1; i < sz; ++i) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};