/*
    146. LRU Cache
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    Follow up:
    Could you do get and put in O(1) time complexity?

    Example 1:
    Input
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
    [null, null, null, 1, null, -1, null, -1, 3, 4]

    Explanation
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
    
    Constraints:

    1 <= capacity <= 3000
    0 <= key <= 3000
    0 <= value <= 104
    At most 3 * 104 calls will be made to get and put.
 */

#include <list>
#include <unordered_map>

using namespace std; 

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;         
    }
    
    int get(int key) {        
        if (_mapKeyItr.find(key) == _mapKeyItr.end()) {
            // the key has not been registered
            return -1; 
        }
        else {
            /**
             * the key is found in the map:
             * - reorder the node assiciated with the key to the front of the cache
             * - return the value
             **/
            const auto& itr{_mapKeyItr[key]}; 
            _cacheLRU.splice(_cacheLRU.begin(), _cacheLRU, itr);
            return itr->second;
        }        
    }
    
    void put(int key, int value) {        
        if (_mapKeyItr.find(key) != _mapKeyItr.end()) {
            /**
             * the key already exist:
             * - update the value associated with the key
             * - move the node associdated with key to the front
             **/
            _mapKeyItr[key]->second = value; 
            _cacheLRU.splice(_cacheLRU.begin(), _cacheLRU, _mapKeyItr[key]);
            return;
        }
        else {
            /**
             * the key does not exist
             * - check the size of the cache; if it is full, remove the last node in the cache
             * - insert a new node at the front of the cache
             **/             
            if (_cacheLRU.size() == _capacity) {
                const auto& pairKeyVal = _cacheLRU.back();
                _mapKeyItr.erase(pairKeyVal.first);
                _cacheLRU.pop_back();
            }                        
            _cacheLRU.emplace_front(key, value);
            _mapKeyItr.insert(make_pair(key, _cacheLRU.begin()));            
            return; 
        }        z
    }
    
private: 
    int _capacity{0};
    /**
     * map is used for O[1] access of the key and node
     * - key is a integer
     * - val: a list iterator that points to a node in the list
     * 
     * doubly linked list is used to maintain the order
     * - nodes in this list are pointed by the iterators as registered in the map
     **/
    unordered_map<int, list<pair<int, int>>::iterator> _mapKeyItr;    
    list<pair<int, int>> _cacheLRU;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */