/*
    311. Sparse Matrix Multiplication

    Given two sparse matrices A and B, return the result of AB.

    You may assume that A's column number is equal to B's row number.

    Example:

    Input:

    A = [[ 1, 0, 0],
         [-1, 0, 3]]

    B = [[ 7, 0, 0 ],
         [ 0, 0, 0 ],
         [ 0, 0, 1 ]]

    Output:

         |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
    AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                      | 0 0 1 |
    
    Constraints:

    1 <= A.length, B.length <= 100
    1 <= A[i].length, B[i].length <= 100
    -100 <= A[i][j], B[i][j] <= 100
 */

#include <vector>

using namespace std; 

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> result; 
        
        // get the size of the matrices
        int rowNumA = A.size();
        int colNumA = A[0].size();
        
        int rowNumB = B.size();
        int colNumB = B[0].size();
        
        assert(colNumA == rowNumB); 
        
        for (int i = 0; i < rowNumA; ++i) {            
            vector<int> row;                         
            for (int j = 0; j < colNumB; ++j) {                
                int sum{0};                 
                for (int k = 0; k < colNumA; k++) {                    
                    sum += A[i][k] * B[k][j];                     
                }                
                row.push_back(sum); 
            }            
            result.push_back(row);             
        }
        
        return result;         
        
    }
};