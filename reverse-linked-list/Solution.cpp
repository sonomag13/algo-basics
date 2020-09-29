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
    ListNode * reverse(ListNode * head) {
        
        if (!head) {
            return NULL; 
        }
        
        reverse_by_recursion(head); 
        return this->newHead; 
    }
    
private: 
    ListNode* newHead{NULL}; 
    
    ListNode* reverse_by_recursion(ListNode* curNode) {
        if (curNode->next == NULL) {
            this->newHead = curNode; 
            return curNode; 
        }
        
        ListNode* preNode = reverse_by_recursion(curNode->next);
        preNode->next = curNode; 
        curNode->next = NULL; 
        
        return curNode; 
        
    } 
    
};