#define INVALID 10001

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        for(int& num : nums)
            sum += num;

        int rem = sum % 3;

        if(rem == 0)
            return sum;

        int min_rem = INVALID;
        for(int& num : nums) {
            if(num % 3 == rem && num < min_rem)
                min_rem = num;
        }

        rem = 3 - rem;

        int min_rem_pair[2] = {INVALID, INVALID};
        for(int& num : nums) {
            if(num % 3 == rem && num < max(min_rem_pair[0], min_rem_pair[1])) {
                if(min_rem_pair[0] > min_rem_pair[1])
                    min_rem_pair[0] = num;
                else
                    min_rem_pair[1] = num;
            }
        }

        if(min_rem == INVALID && (min_rem_pair[0] == INVALID || min_rem_pair[1] == INVALID))
            return 0;
        
        return sum - min(min_rem, min_rem_pair[0] + min_rem_pair[1]);
    }
};