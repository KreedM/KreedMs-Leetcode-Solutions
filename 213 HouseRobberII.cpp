class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }

private:
    int rob(vector<int>& nums, int start, int end) {
        int prev = 0, curr = nums[start], temp;

        for(int i = start + 1; i < end; ++i) {
            temp = curr;
            curr = max(curr, prev + nums[i]);
            prev = temp;
        }

        return curr;
    }
};