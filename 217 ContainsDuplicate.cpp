class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> noDupes; //noDupes.reserve(nums.size());

        for(const int& num : nums) {
            if(noDupes.find(num) != noDupes.end())
                return true;
            
            noDupes.insert(num);
        }

        return false;
    }
};