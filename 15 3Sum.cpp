class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;

        int left, right, sum;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            left = i + 1; right = nums.size() - 1;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];

                if(sum > 0)
                    --right;
                else if (sum < 0)
                    ++left;
                else {
                    triplets.push_back(vector<int>(3));
                    triplets.back()[0] = nums[i]; triplets.back()[1] = nums[left]; triplets.back()[2] = nums[right];

                    while(nums[++left] == nums[left - 1] && left < right);
                }
            }
        }

        return triplets;
    }
};