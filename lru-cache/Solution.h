// LeetCode 146. LRU Cache
// medium

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