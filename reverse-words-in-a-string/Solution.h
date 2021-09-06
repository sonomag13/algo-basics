// LeetCode 151. Reverse Words in a String
// Medium

#include <stack>
#include <string>

using namespace std; 

class Solution {
public:
    string reverseWords(string s) {
        
        string result = ""; 
        
        stack<string> stkWord; 
        
        int i = 0; 
        while (i < s.size()) {                        
            
            string word{""};
            
            if (s[i] == ' ') {
                i++; 
                continue; 
            }
            
            word += s[i]; 
            
            int j = i + 1; 
            
            while (j < s.size() && s[j] != ' ') {
                word += s[j];
                j++; 
            } 
            i = j;             
            stkWord.push(word);            
        }        
        
        result += stkWord.top();
        stkWord.pop(); 
        
        while (!stkWord.empty()) {
            result += " " + stkWord.top();
            stkWord.pop();
        }
        
        return result; 
        
    }
};