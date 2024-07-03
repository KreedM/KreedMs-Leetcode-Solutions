class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;

        combinationSum(candidates, 0, 0);

        return combinations;
    }

private:
    int target;
    vector<int> combination;
    vector<vector<int>> combinations;

    void combinationSum(vector<int>& candidates, const int& i, const int& from) {
        if(i == candidates.size())
            return;

        if(from == target) {
            combinations.push_back(combination);
            return;
        }

        if(from + candidates[i] <= target) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, i, from + candidates[i]);
            combination.pop_back();
        }

        combinationSum(candidates, i + 1, from);
    }
};