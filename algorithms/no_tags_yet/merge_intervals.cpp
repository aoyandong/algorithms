/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
bool compare(const Interval &a, const Interval &b){
        return a.start<b.start;
}

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        int n = intervals.size();
        if (n<=1) return intervals;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<Interval> res;
        int cur_start=intervals[0].start, cur_end=intervals[0].end;
        for (int i=0; i<intervals.size(); i++){
            if (intervals[i].start>cur_end){
                res.push_back(Interval(cur_start,cur_end));
                cur_start = intervals[i].start;
                cur_end = intervals[i].end;
            }
            else cur_end = max(cur_end, intervals[i].end);
        }
        res.push_back(Interval(cur_start,cur_end));
        
        return res;
    }
};
