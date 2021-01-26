#include <iostream>

#include "Fib.h"

using namespace std; 

int main() {

    const int num{10};
    
    cout << "result of method 1 = " << calcFib1(num) << endl; 
    cout << "result of method 2 = " << calcFib2(num) << endl; 

    return 0; 

}