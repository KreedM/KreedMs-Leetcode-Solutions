class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int sz = intervals.size();

        vector<vector<int>> inserted; inserted.reserve(sz + 1);

        int i = 0;

        while(i < sz && intervals[i][1] < newInterval[0])
            inserted.push_back(intervals[i++]);

        if(i < sz && intervals[i][0] < newInterval[1])
            newInterval[0] = min(newInterval[0], intervals[i][0]);
        
        while(i < sz && intervals[i][0] <= newInterval[1])
            newInterval[1] = max(newInterval[1], intervals[i++][1]);

        inserted.push_back(newInterval);

        while(i < sz)
            inserted.push_back(intervals[i++]);

        return inserted;
    }
};