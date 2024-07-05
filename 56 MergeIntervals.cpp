class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged; merged.reserve(sz);

        merged.push_back({intervals[0][0], intervals[0][1]});

        for(int i = 1; i < sz; ++i) {
            if(intervals[i][0] <= merged.back()[1])
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            else 
                merged.push_back({intervals[i][0], intervals[i][1]});
        }

        return merged;
    }
};