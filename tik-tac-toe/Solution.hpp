#include <vector>

using namespace std; 

class TicTacToe {
public:
    TicTacToe(int n): n(n) {
        // initialize the object
        rowSum = vector<int>(n, 0); 
        colSum = vector<int>(n, 0);
        diag1Sum = 0;
        diag2Sum = 0;
    }
    
    int move(int row, int col, int player) {
        /** 
         * How do check the winner? 
         * 
         * If a row, a column or a diagnal line is filled up with 1 or -1
         * (that represent player1 and player2), the sum long the line is 
         * +n or -n
         */

        int delta = player == 1 ? 1 : -1; 

        rowSum[row] += delta; 
        if (abs(rowSum[row]) == n) {
            return player; 
        }

        colSum[col] += delta; 
        if (abs(colSum[col]) == n) {
            return player;
        }

        if (row == col) {
            diag1Sum += delta; 
            if (abs(diag1Sum) == n) {
                return player;
            }
        }

        if (row == n - col - 1) {
            diag2Sum += delta; 
            if (abs(diag2Sum) == n) {
                return player;
            }
        }

        return 0; 
    }

private: 
    int n; 
    vector<int> rowSum; 
    vector<int> colSum;
    int diag1Sum;
    int diag2Sum; 
    
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */