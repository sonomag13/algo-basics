/*
    268. Missing Number
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

    Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

    

    Example 1:

    Input: nums = [3,0,1]
    Output: 2
    Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
    Example 2:

    Input: nums = [0,1]
    Output: 2
    Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
    Example 3:

    Input: nums = [9,6,4,2,3,5,7,0,1]
    Output: 8
    Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
    Example 4:

    Input: nums = [0]
    Output: 1
    Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
 */

#include <vector>

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        /**
         * Notice the range of the number is [0, n], meaning 
         * that the there are n + 1 element in this interval; 
         * however, the size of the vector is n, and this mismatch 
         * ensure that a missing number must exist. 
         **/
        
        int missingNum;                 
        
        // sort the numbers
        sort(nums.begin(), nums.end()); 
        
        /*
         * The tricky part of this problem is the corner cases
         * - the first element is not zero
         * - the last element is not n
         * 
         * For example, if the vector is [1, 2, ..., n], the the 
         * loop below cannot detect that the first element is not 0. 
         * 
         * Likewise if the last number is not n (this implies that 
         * the last element is n - 1), the for loop cannot detect it 
         * neither since all the elements are indeed sequential.
         */
        if (nums[0] != 0) {
            return 0; 
        }
        if (nums[numsSize - 1] != numsSize) {
            return nums[numsSize - 1] + 1; 
        }
        
        // travers the vector to check if the numbers are consequential
        for (int i = 1; i < numsSize; ++i) {
            if (nums[i] - nums[i - 1] != 1) {
                missingNum = nums[i] -1; 
                break;
            }
        }
        
        return missingNum; 
        
    }
    
};