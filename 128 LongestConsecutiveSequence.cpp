class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        unordered_set<int> sequences; sequences.reserve(nums.size());

        for(int i = 0; i < nums.size(); ++i)
            sequences.insert(nums[i]);

        int count = 1, curr_count = 1;
        for(const int& num : sequences) {
            if(sequences.find(num - 1) == sequences.end()) {
                curr_count = 0;

                while(sequences.find(num + ++curr_count) != sequences.end());

                count = max(count, curr_count);
            }
        }

        return count;
    }
};