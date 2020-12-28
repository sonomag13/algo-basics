/*
    56. Merge Intervals

    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

    Example 1:
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
    
    Example 2:
    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.
    
    Constraints:
    1 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= start_i <= end_i <= 10^4
 */

#include <vector>

using namespace std;

class Solution {
public:    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;                 
        
        // sort the vectors with the first number in the interval
        auto comparator = [] (const vector<int>& intvl1, const vector<int>& intvl2) {
            return  intvl1[0] < intvl2[0];
        };        
        sort(intervals.begin(), intervals.end(), comparator);        
        
        /**
         * Initially, push the first interval (i.e. with the smallest first number
         * across the intervals) into the result 
         * 
         * Traverse the rest of the intervals. If the first number of the current 
         * interal is less than the last interval in the result, there is an overlap
         * such that reset the second number of the last interval in the result
         * 
         * Otherwise, there is no overlap between the last interval in the result and 
         * the current interval, then push the interval into the result
         **/ 
        result.push_back(intervals[0]);        
        for (int i = 1; i < intervals.size(); ++i) {            
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {                
                result.push_back(intervals[i]);
            }            
        }
        
        return result;
        
    }
    
};