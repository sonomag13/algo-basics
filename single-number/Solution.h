// LeetCode 136. Single Number
// Easy

#include <vector>

using namespace std; 

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = nums[0]; 
        
        // a^a = 0
        // a^0 = a
        // XOR is asscoiative and permutable
        // a ^ b ^ a = (a ^ a) ^ b = b
        for (int i = 1; i < nums.size(); ++i) {            
            result ^= nums[i];             
        }
        
        return result; 
        
    }
};