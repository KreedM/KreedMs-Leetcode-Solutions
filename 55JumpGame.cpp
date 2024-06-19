class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reaches = nums.size() - 1;

        for(int i = reaches - 1; i > -1; --i) {
            if(i + nums[i] >= reaches)
                reaches = i;
        }

        return reaches == 0;
    }
};