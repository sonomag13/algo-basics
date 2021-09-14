// LeetCode 277. Find the Celebrity
// Medium

/* The knows API is defined for you.
      bool knows(int a, int b); */

bool knows(int, int); 

class Solution {
public:
    int findCelebrity(int n) {        
        /*
            What does knows(a, b) tell us? 
            - true: a is not a celerbrity
            - false: b is not a celerity
         */
        
        // to make the problm simpler, let us find out the candidate of the celerbrity
        int candidate = 0; 
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) {
                // candidate should now know other people
                // candidate does not know i - 1, which implies:
                // - candidate is a valid candidate at least for i - 1
                // - i - 1 is not a candidate since candidate does not know i - 1
                candidate = i;
            }
        }
        
        // hereby, we know that candidate that does not know any one else
        // but what about if everyone else know the candidate? let us validate it
        for (int i = 0; i < n; ++i) {            
            if (candidate == i) {
                continue; 
            }
            if (!knows(i, candidate) || knows(candidate, i)) {
                // i does not know the candidate, or the candidate knows i, 
                // the candidate is disqualified
                return -1; 
            }        
        }
        
        return candidate; 
        
    }
};