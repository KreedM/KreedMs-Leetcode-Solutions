/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), compare);

        priority_queue<int, vector<int>, greater<int>> days; // Stores most recently scheduled interval for each day
        days.push(intervals.front().end);

        int n = intervals.size();
        for(int i = 1; i < n; ++i) {
            if(intervals[i].start >= days.top())
                days.pop();

            days.push(intervals[i].end);
        }

        return days.size();
    }
private:
    static bool compare(const Interval& a, const Interval& b) {
        return a.end < b.end;
    }
};
