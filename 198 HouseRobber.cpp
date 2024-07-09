class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev = 0, curr = nums[0], temp;

        for(int i = 1; i < nums.size(); ++i) {
            temp = curr;
            curr = max(curr, prev + nums[i]);
            prev = temp;
        }

        return curr;
    }
};