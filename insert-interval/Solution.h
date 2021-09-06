// LeetCode 57. Insert Interval
// Medium

#include <algorithm>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            
        vector<vector<int>> result; 
        
        if (!intervals.size()) {
            result.push_back(newInterval);
            return result; 
        }
        
        intervals.push_back(newInterval); 
        
        sort(intervals.begin(), intervals.end());  
        
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            
            int lastIdx = result.size() - 1; 
            
            if (intervals[i][0] <= result[lastIdx][1]) {
                // there is overlapping
                result[lastIdx][1] = max(result[lastIdx][1], intervals[i][1]);
            }            
            else {
                // no overlapping
                result.push_back(intervals[i]);
            }
            
        }
                
        return result; 
        
    }
};