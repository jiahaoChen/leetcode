/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (!n) return intervals;
        // std::sort(intervals.begin(), intervals.end(), func); // the function for static like
		std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            if (ret.back().end >= intervals[i].start) {
                if (ret.back().end < intervals[i].end)
                    ret.back().end = intervals[i].end;
            }
            else {
                ret.push_back(intervals[i]);
            }

        }

        return ret;
    }
    static bool func (Interval i,Interval j) { return (i.start<j.start); }

};