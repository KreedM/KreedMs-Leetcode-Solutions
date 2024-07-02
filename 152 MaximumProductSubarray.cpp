class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums.front();

        long long product = 1;
        for(int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            
            if(product < INT_MIN)
                break;

            maxP = max(maxP, (int)product);
            
            if(nums[i] == 0)
                product = 1;
        }

        product = 1;
        for(int i = nums.size() - 1; i >= 0; --i) {
            product *= nums[i];
            maxP = max(maxP, (int)product);

            if(product < INT_MIN)
                break;
            
            if(nums[i] == 0)
                product = 1;
        }

        return maxP;
    }
};