class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int overlap = 0, end = -5e4-1;
        for(const vector<int>& interval : intervals) {
            if(interval[0] >= end)
                end = interval[1];
            else
                ++overlap;
        }

        return overlap;
    }

private:
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
};