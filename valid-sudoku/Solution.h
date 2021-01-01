/*
    36. Valid Sudoku
    Medium

    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
    

    Example 1:
    Input: board = 
    [["5","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: true

    Example 2:
    Input: board = 
    [["8","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: false
    Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 */

#include <unordered_map>
#include <vector>

using namespace std; 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rowNum{9}, colNum{9}; 
        
        // check the size in terms of row number and column number
        if (board.size() != rowNum) {
            return false; 
        }        
        for (auto& row : board) {
            if (row.size() != colNum) {
                return false; 
            }
        }
        
        _initializeMap();
        
        // check if there is repeating in the global scope
        if (!_checkRepeatingChar(board, make_pair(0, rowNum), make_pair(0, colNum))) {
            return false; 
        }
        
        // check sub-block
        for (int i = 0; i < rowNum; i = i + 3) {
            for (int j = 0; j < colNum; j = j + 3) {
                if (!_checkRepeatingChar(board, make_pair(i, i + 3), make_pair(j, j + 3))) {
                    return false; 
                }                
            }            
        }
        
        return true; 
        
    }
                
private:     
    
    /**
     * key: digits
     * val: count of the key that cannot exceed 1
     **/
    unordered_map<int, int> _mapDigitCounts;         
    
    // initialze the map
    void _initializeMap() {
        for (int i = 1; i <= 9; ++i) {
            _mapDigitCounts.insert(make_pair(i, 0));
        }
    }
    
    // reset the count of the values
    void _resetMap() {
        for (auto& ele : _mapDigitCounts) {
            ele.second = 0;
        }
    }
    
    // check if the val is a number in the rnage of [1, 9]
    bool _isDigit(int val) {
        return 1 <= val && val <= 9; 
    }
        
    bool _checkRepeatingChar(const vector<vector<char>>& board, const pair<int, int>& rowRange, const pair<int, int>& colRange) {
                                                        
        // get the range of the block                                                        
        int row1{rowRange.first}, row2{rowRange.second};
        int col1{colRange.first}, col2{colRange.second};                        
        assert(row2 - row1 == col2 - col1); 

        // if it is a sub-block problem, check the repeating character in 3 x 3 scope
        if (row2 - row1 == 3) {
            for (int colIdx = col1; colIdx < col2; ++colIdx) {
                for (int rowIdx = row1; rowIdx < row2; ++rowIdx) {
                    int val{board[rowIdx][colIdx] - '0'};                                
                    if (_isDigit(val)) {
                        if (_mapDigitCounts[val] == 1) {
                            // the number is repeated
                            return false; 
                        }
                        else {
                            // the number is not repeated and increase the count
                            _mapDigitCounts[val] = 1;                        
                        }                
                    }
                }
            }
            _resetMap();
        }

        // check the number repeating along the row
        for (int rowIdx = row1; rowIdx < row2; ++rowIdx) {
            for (int colIdx = col1; colIdx < col2; ++colIdx) {
                int val{board[rowIdx][colIdx] - '0'};                                
                if (_isDigit(val)) {
                    if (_mapDigitCounts[val] == 1) {
                        // the number is repeated
                        return false; 
                    }
                    else {
                        // the number is not repeated and increase the count
                        _mapDigitCounts[val] = 1;                        
                    }                
                }
            }
            _resetMap();
        }
        
        // check the number repeating along the column
        for (int colIdx = col1; colIdx < col2; ++colIdx) {
            for (int rowIdx = row1; rowIdx < row2; ++rowIdx) {
                int val{board[rowIdx][colIdx] - '0'};                                
                if (_isDigit(val)) {
                    if (_mapDigitCounts[val] == 1) {
                        // the number is repeated
                        return false; 
                    }
                    else {
                        // the number is not repeated and increase the count
                        _mapDigitCounts[val] = 1;                        
                    }                
                }
            }
            _resetMap();
        }        
        
        return true; 
        
    }            
        
};