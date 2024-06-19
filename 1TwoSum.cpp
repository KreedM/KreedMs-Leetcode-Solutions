#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;

        unordered_map<int, int> complements;

        for(int i = 0; i < nums.size(); ++i) {
            if(complements.find(target - nums[i]) != complements.end()) {
                answer.push_back(i);
                answer.push_back(complements[target - nums[i]]);
                break;
            }
            else
                complements[nums[i]] = i;
        }

        return answer;
    }
};