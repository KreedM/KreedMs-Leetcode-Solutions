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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int start = 0, end = 0;
        for(const Interval& interval : intervals) {
            if(interval.start >= start && interval.start < end)
                return false;

            start = interval.start;
            end = max(end, interval.end);
        }

        return true;
    }

private:
    static bool compare(Interval i1, Interval i2)
    {
        return i1.start < i2.start;
    }
};