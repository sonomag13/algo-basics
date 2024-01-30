// 134. Gas Station

#include <iostream>
#include <numeric>

using namespace std; 

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        if (gas.empty() || cost.empty()) {
            return -1; 
        } 

        int totalGas = accumulate(gas.begin(), gas.end(), 0); 
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if (totalGas < totalCost) {
            return -1; 
        } 

        // the total amount of gas is more than that of cost. 
        // A unique solution is guaranteed

        int start = 0; 
        int gasInTank = 0; 
        int numStation = gas.size(); 

        for (int i = 0; i < numStation; ++i) {
            gasInTank += gas[i] - cost[i]; 
            if (gasInTank < 0) {
                // the car cannot move from i to i + 1, so that let use the next 
                // station as the new start, and zero the gas left in the tank
                start = i + 1;
                gasInTank = 0; 
            }
        } 

        return start; 
    }
};