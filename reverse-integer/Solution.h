/*
    7. Reverse Integer
    Given a 32-bit signed integer, reverse digits of an integer.

    Note:
    Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

    Example 1:
    Input: x = 123    
    Output: 321

    Example 2:
    Input: x = -123
    Output: -321
    
    Example 3:
    Input: x = 120
    Output: 21

    Example 4:
    Input: x = 0
    Output: 0
    
    Constraints:
    -2^31 <= x <= 2^31 - 1
 */

class Solution {

public:
    int reverse(int x) {
        
        int reversedInteger{0};         
        
        while (x) {            
            // get a digit at the end and shift the number to left by 10
            int digits{x%10};
            x /= 10;       
            
            // handle overflow for positive case and negative case
            bool condOverflow1{(INT_MAX / 10 < reversedInteger) || 
                               (INT_MAX / 10 == reversedInteger && INT_MAX % 10 > 7)};            
            bool condOverflow2{(INT_MIN / 10 > reversedInteger) || 
                               (INT_MIN / 10 == reversedInteger && INT_MAX % 10 < -8)};                                    
            if (condOverflow1 || condOverflow2) {
                return 0; 
            }                        
            
            // no overflow
            reversedInteger = reversedInteger * 10 + digits;             
        }
                
        return reversedInteger; 
        
    }
};