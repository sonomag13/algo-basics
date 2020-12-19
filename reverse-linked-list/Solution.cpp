/*
    35. Reverse Linked List    
    Reverse a linked list.

    Example
    Example 1:

    Input: 1->2->3->null
    Output: 3->2->1->null
    Example 2:

    Input: 1->2->3->4->null
    Output: 4->3->2->1->null
    Challenge
    Reverse it in-place and in one-pass
 */

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */

    ListNode * reverse_nonrecrusive(ListNode * head) {
        // write your code here        
        if (head == NULL) {
            return NULL; 
        }        
        ListNode* prevNode = NULL; 
        ListNode* currentNode = head;         
        while(currentNode != NULL) {
            ListNode* nextNode = currentNode->next;
            currentNode->next = prevNode; 
            prevNode = currentNode; 
            currentNode = nextNode; 
        }        
        return prevNode;         
    }

    ListNode * reverse(ListNode * head) {
        
        if (!head) {
            return NULL; 
        }
        
        _reverse_by_recursion(head); 
        return this->newHead; 
    }
    
private: 
    ListNode* newHead{NULL}; 
    
    // reverse the list recursively
    ListNode* _reverse_by_recursion(ListNode* curNode) {
        // base case
        if (curNode->next == NULL) {
            this->root = curNode; 
            return root; 
        }
        
        /*
            - 
            - link the current node to the next pointer of the previous node
            - nollify the next pointer of the prevous node        
         */ 
        
        // calculate the previous node
        ListNode* preNode = _reverseList(curNode->next);
        
        /*
         * Solution 1
         * - create a new node with the value value of the current node with null next pointer
         * - return the new node
         */
        auto newNode = new ListNode(curNode->val); 
        preNode->next = newNode; 
        return newNode;          
                
        /*
         * Solution 2
         * - nullify the next pointer of the current node
         * - return the current node
         */
        /*
        preNode->next = curNode;
        curNode->next = NULL; 
        return curNode;                  
         */
    } 
    
};