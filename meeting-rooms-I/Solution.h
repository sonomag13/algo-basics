/*
    920. Meeting Rooms

    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

    Example
    Example1

    Input: intervals = [(0,30),(5,10),(15,20)]
    Output: false
    Explanation: 
    (0,30), (5,10) and (0,30),(15,20) will conflict
    Example2

    Input: intervals = [(5,8),(9,15)]
    Output: true
    Explanation: 
    Two times will not conflict 
    Notice
    (0,8),(8,10) is not conflict at 8
 */


/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        
        /**
         * create a comparator to sort the intervals by the start value
         * the return of this lambda function determins is the first argument
         * precedes the second, or in other words, the first argument
         * should be before the second argument
         */ 
        auto comp = [] (const Interval& int1, const Interval& int2) {
            if (int1.start != int2.start) {
                return int1.start < int2.start; 
            }
            else {
                return int1.end < int2.end; 
            }
        };

        // sort the time intervals by the start time
        sort(intervals.begin(), intervals.end(), comp); 
        

        /**
         * the interval has been sorted by the starting value
         * if the next meeting has the starting time less than the
         * end time of the previous meeting, then conflict occurs 
         */
        for (int i = 1; i < intervals.size(); ++i) {
            if(intervals[i-1].end > intervals[i].start) {
                return false; 
            }
        }
        
        return true; 
    
    }
    
};