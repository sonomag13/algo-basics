/*
    54. Spiral Matrix
    Medium

    Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]

    Example 2:
    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    

    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
 */

#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; 
        
        if (matrix.empty() || matrix[0].empty()) {
            return result; 
        }
        
        result = _spiralOrder(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1); 
        
        return result;         
    }
    
private: 
    vector<int> _spiralOrder(const vector<vector<int>>& matrix, int rowIdx1, int rowIdx2, int colIdx1, int colIdx2) {
        
        // interval is defined as [rowIdx1, rowIdx2] and [colIdx1, colIdx2]
        vector<int> outerSpiral{};                 
        if (rowIdx1 > rowIdx2 || colIdx1 > colIdx2) {
            return outerSpiral; 
        }
        
        // upper line from right to left
        for (int colIdx = colIdx1; colIdx <= colIdx2; ++colIdx) {
            outerSpiral.push_back(matrix[rowIdx1][colIdx]); 
        }
        
        // right column from top to bottom
        for (int rowIdx = rowIdx1 + 1; rowIdx <= rowIdx2 - 1; ++rowIdx) {
            outerSpiral.push_back(matrix[rowIdx][colIdx2]); 
        }
        
        // bottom line from left to right
        if (rowIdx1 != rowIdx2) {
            for (int colIdx = colIdx2; colIdx >= colIdx1; --colIdx) {
                outerSpiral.push_back(matrix[rowIdx2][colIdx]);                 
            }
        }
        
        // left column from bottom to top
        if (colIdx1 != colIdx2) {
            for (int rowIdx = rowIdx2 - 1; rowIdx >= rowIdx1 + 1; --rowIdx) {
                outerSpiral.push_back(matrix[rowIdx][colIdx1]); 
            }
        }        
        
        // get the inner spiral
        vector<int> innerSpiral {_spiralOrder(matrix, rowIdx1+1, rowIdx2-1, colIdx1+1, colIdx2-1)}; 
        
        // combine the inner spiral and outer spiral
        for (auto val : innerSpiral) {
            outerSpiral.push_back(val); 
        }
        
        return outerSpiral; 
        
    }
    
};