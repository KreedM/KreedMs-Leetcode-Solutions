class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();

        vector<int> products(len);

        int product = 1; // Prefix
        for(int i = 0; i < len; ++i) {
            products[i] = product;
            product *= nums[i];
        }

        product = nums.back(); // Suffix
        for(int i = len - 2; i >= 0; --i) {
            products[i] *= product;
            product *= nums[i];
        }

        return products;
    }
};