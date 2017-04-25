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
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        if (intervals.size()==0) return vector<Interval>(1,newInterval);
        int left=-1, right=intervals.size();
        for (int i=0; i<intervals.size(); i++){
            if (intervals[i].end<newInterval.start) left = i;
            else break;
        }
        for (int i=left+1; i<intervals.size(); i++){
            if (intervals[i].start>newInterval.end) {right = i; break;}
        }
        
        vector<Interval> res(intervals.begin(), intervals.end());
        if (left+1==right) res.insert(res.begin()+right, newInterval);
        else{
            newInterval.start = min(newInterval.start, intervals[left+1].start);
            newInterval.end = max(newInterval.end, intervals[right-1].end);
            res.erase(res.begin()+left+1, res.begin()+right);
            res.insert(res.begin()+left+1,newInterval);
        }
        return res;
    }
};
