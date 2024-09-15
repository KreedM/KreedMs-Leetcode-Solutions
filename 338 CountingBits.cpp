class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1); ans[0] = 0;

        int count = 0, power = 1;
        while(++count <= n) {
            if(count - power == power) {
                ans[count] = 1;
                power = count;
            }
            else
                ans[count] = ans[count - power] + 1;
        }

        return ans;
    }
};