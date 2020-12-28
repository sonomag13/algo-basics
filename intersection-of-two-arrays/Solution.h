
#include <set>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // lambda function to set up the set        
        auto getSetVal = [] (const vector<int>& nums) {
            set<int> setVal; 
            for (auto val : nums) {
                setVal.insert(val);
            }
            return setVal; 
        };
        
        // lambda function to find the intersection
        auto findIntersection = [] (const set<int>& setVal, const vector<int>& nums) {
            set<int> intersection;             
            for (auto val : nums) {
                if (setVal.find(val) != setVal.end()) {
                    intersection.insert(val); 
                }
            }            
            return intersection; 
        };

        // get the set of values and find the intersection                
        set<int> setVal;
        set<int> intersection;
        if (nums1.size() > nums2.size()) {
            setVal = getSetVal(nums2); 
            intersection = findIntersection(setVal, nums1); 
        }
        else {
            setVal = getSetVal(nums1); 
            intersection = findIntersection(setVal, nums2); 
        }         
        
        // convert the set to vector
        vector<int> result; 
        for (auto val : intersection) {
            result.push_back(val); 
        }
        
        return result;         
        
    }
    
};