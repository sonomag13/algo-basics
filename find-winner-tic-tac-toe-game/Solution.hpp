// 1275. Find Winner on a Tic Tac Toe Game

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {

        vector<int> sumRow(3, 0);
        vector<int> sumCol(3, 0);
        int sumDiag1 = 0; 
        int sumDiag2 = 0; 
        int numMoves = 0; 

        for (int i = 0; i < moves.size(); ++i) {
            string player; 
            int delta; 
            if (i%2 == 0) {
                player = "A"; 
                delta = +1; 
            }
            else {
                player = "B"; 
                delta = -1; 
            }
            int rowIdx = moves[i][0];
            int colIdx = moves[i][1];

            sumRow[rowIdx] += delta; 
            bool cond1 = abs(sumRow[rowIdx]) == 3;

            sumCol[colIdx] += delta; 
            bool cond2 = abs(sumCol[colIdx]) == 3;

            bool cond3 = false;
            if (rowIdx == colIdx) {
                sumDiag1 += delta; 
                if (abs(sumDiag1) == 3) {
                    cond3 = true; 
                }
            }

            bool cond4 = false;
            if (rowIdx == 3 - colIdx - 1) {
                sumDiag2 += delta; 
                if (abs(sumDiag2) == 3) {
                    cond4 = true; 
                }
            }

            if (cond1 || cond2 || cond3 || cond4) {
                return player; 
            }
        }

        if (moves.size() < 9) {
            return "Pending"; 
        }

        return "Draw"; 
    }
};