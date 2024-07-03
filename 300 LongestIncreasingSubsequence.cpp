class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis; // Min ending val of LIS of length i + 1;

        int len;
        for(const int& num : nums) {
            len = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

            if(len == lis.size())
                lis.push_back(num);
            else
                lis[len] = num;
        }

        return lis.size();

    /*
        int sz = nums.size();

        vector<int> lis(sz); lis[0] = 1;

        int len = 1;
        for(int i = 1; i < sz; ++i) {
            lis[i] = 1;

            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j])
                    lis[i] = max(lis[i], lis[j] + 1);
            }

            len = max(len, lis[i]);
        }

        return len;
    */
    }
};