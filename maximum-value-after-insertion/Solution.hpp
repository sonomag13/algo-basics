// 1881. Maximum Value after Insertion

#include <iostream>

using namespace std; 

class Solution {
public:
    string maxValue(string n, int x) {
        
        string strOut; 

        if (n[0] == '-') {
            strOut = _insertCharNegativeNumber(n, x); 
        }
        else {
            strOut = _insertCharPositiveNumber(n, x); 
        }

        return strOut; 
    }

private: 
    string _insertCharPositiveNumber(const string & strIn, int x) {
        stringstream ss; 

        int posInsert = strIn.length(); 

        for (int i = 0; i < strIn.length(); ++i) {
            int curVal = strIn[i] - '0'; 
            if (x > curVal) {
                // insert x to make number more positive
                ss << to_string(x);
                posInsert = i; 
                break;  
            }
            ss << strIn[i];
        }

        if (posInsert == strIn.length()) {
            // x is not inserted
            ss << to_string(x);
        }
        else {
            ss << strIn.substr(posInsert); 
        }

        return ss.str(); 
    }

    string _insertCharNegativeNumber(const string & strIn, int x) {
        stringstream ss; 

        ss << strIn[0];  // negative sign

        int posInsert = strIn.length(); 

        for (int i = 1; i < strIn.length(); ++i) {
            int curVal = strIn[i] - '0'; 
            if (x < curVal) {
                // insert x to make the number less negative
                ss << to_string(x);
                posInsert = i; 
                break;  
            }
            ss << strIn[i];
        }

        if (posInsert == strIn.length()) {
            // x is not inserted
            ss << to_string(x);
        }
        else {
            ss << strIn.substr(posInsert); 
        }

        return ss.str(); 
    }
};