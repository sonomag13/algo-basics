// F0=0; F1=1; F(n) = F(n-1) +F(n-2); n=100000, F(n) = ? 
#include <cmath>

int calcFib1(int n) {

    int memo[2] = {0, 1}; 

    for (int i = 2; i <= n; ++i) {        
        int sum = memo[0] + memo[1]; 
        memo[0] = memo[1];
        memo[1] = sum; 
    }

    return memo[1]; 

}


int calcFib2(int n) {

    // Base case 1
    if (n == 0) {
        return 0; 
    }
    /**
     * Base case 2
     * Notice that f(1) = f(2) = 1, such that we consider n = 2 is a base case; if not, whenever calling f(2),
     * we have calcFib2(2/2 + 1) = calcFib(2), which will keep calculating f(2). This is an dead end.
     **/
    if (n == 1 || n == 2) {
        return 1; 
    }

    /**
     * in the recursion, the n has been cut into half, such that 
     * the time complexity is log(n)
     **/
    if (n%2 == 0) {
        // n is even, such that F(2n) = F(n) * (2F(n+1) - F(n))
        return calcFib2(n/2) * (2 * calcFib2(n/2+1) - calcFib2(n/2));
    }
    else {
        // n is odd, such that F(2n+1) = F(n+1)^2 + F(n)^2;
        return pow(calcFib2(n/2+1), 2) + pow(calcFib2(n/2), 2);
    }

}

