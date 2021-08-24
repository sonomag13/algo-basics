/*
    208. Implement Trie (Prefix Tree)
    Medium

    A trie (pronounced as "try") or prefix tree is a tree data structure 
    used to efficiently store and retrieve keys in a dataset of strings. 
    There are various applications of this data structure, such as autocomplete 
    and spellchecker.

    Implement the Trie class:

    Trie() Initializes the trie object.
    
    void insert(String word) Inserts the string word into the trie.
    
    boolean search(String word) Returns true if the string word is in the 
    trie (i.e., was inserted before), and false otherwise.
    
    boolean startsWith(String prefix) Returns true if there is a previously 
    inserted string word that has the prefix prefix, and false otherwise.
    
    Example 1:
    Input
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    Output
    [null, null, true, false, true, null, true]

    Explanation
    Trie trie = new Trie();
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True

 */

#include <iostream>

using namespace std; 

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root(new TrieNode()) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        
        // start the insertion from the root
        TrieNode* currNode = root; 
        
        for (auto c : word) {
            
            int idx = c - 'a'; // the index where the character should be in children
            
            if (!currNode->children[idx]) {
                // the node is not inserted yet, generate a new node
                currNode->children[idx] = new TrieNode(); 
            }
            
            // move the current node to the node correlated to 'c'
            currNode = currNode->children[idx];             
        }
        
        // the word is completed at the current node
        currNode->is_word = true; 
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {

        // if search for a world, the last node as returned must 
        // not be null and the is_word flag is true
        TrieNode* lastNode = searchTrieNode(word);
        return lastNode && lastNode->is_word; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        // if search for the prefix, the last node as returned must
        // not be null
        TrieNode* lastNode = searchTrieNode(prefix);
        return lastNode; 
    }
    
private:
    
    struct TrieNode {
        bool is_word; // a word is completed at this node
        vector<TrieNode*> children; // accommondate 26 letters
        
        // constructor
        TrieNode (): is_word(false), children(26, nullptr) {
            
        }
        
        // destructor
        ~TrieNode () {
            for (auto child : children) {
                if (child) {
                    delete child;
                }
            }
        }
    };
    
    TrieNode* searchTrieNode(const string& word) const {

        // start search from the root
        TrieNode* currNode = root; 

        for (auto c : word) {  
            // traverse each character, if it is in the children, try the next
            // character. If the character is not in the children, return null
            int idx = c - 'a'; 
            currNode = currNode->children[idx];
            if (!currNode) {
                return nullptr; 
            }
        }
        
        return currNode; 
    }
    
    TrieNode* root;  // this is a dummy root 
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */