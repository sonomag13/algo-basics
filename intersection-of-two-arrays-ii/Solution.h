/*
    350. Intersection of Two Arrays II
    Given two arrays, write a function to compute their intersection.

    Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]

    Example 2:
    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [4,9]
    Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.
    Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */

#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
                        
        // by hash map
        if (nums1.size() > nums2.size()) {
            _getMap(nums2); 
            _getIntersection(nums1); 
        }
        else {
            _getMap(nums1); 
            _getIntersection(nums2); 
        }
        
        return _intersection; 
        
    }

    vector<int> intersect_2(vector<int>& nums1, vector<int>& nums2) {
        
        // by sorting                
        vector<int> result; 
        
        // sort array
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // traverse two vectors and append the overlapped values to the result
        int i = 0, j = 0;         
        while (i < nums1.size() && j < nums2.size()) {            
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]); 
                i++; 
                j++;                 
            }            
            else if (nums1[i] < nums2[j]) {
                i++;                 
            }            
            else {
                j++;                 
            }            
        }
                
        return result; 
        
    }
    
private:
    unordered_map<int, int> _mapValCnt; 
    vector<int> _intersection; 
    
    void _getMap(const vector<int>& nums) {        
        for (auto val : nums) {
            if (_mapValCnt.find(val) != _mapValCnt.end()) {
                _mapValCnt[val]++;
            }
            else {
                _mapValCnt.insert(make_pair(val, 1));
            }
        }
    }
    
    void _getIntersection(const vector<int>& nums) {        
        for (auto val : nums) {
            if (_mapValCnt.find(val) != _mapValCnt.end()) {                
                _intersection.push_back(val); 
                _mapValCnt[val]--; 
                if (!_mapValCnt[val]) {
                    _mapValCnt.erase(val);
                }
            }
        }        
    }
    
};