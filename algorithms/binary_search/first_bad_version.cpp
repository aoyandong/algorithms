/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int lo=0, hi=n, mid;
        while((lo+1)<hi){
            mid = lo+(hi-lo)/2;
            if (SVNRepo::isBadVersion(mid)) hi=mid;
            else lo=mid;
        }
        return hi;
    }
};
