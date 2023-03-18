// This is an O(n) solution that operates using recursion. We have the main swapPairs function, which gets called with just the head of the list. 
// This function handles base cases, swaps the first two nodes, and then calls swapPairs with the first node of the next pair, and its 
// previous node. The recursive calls go down the list until they hit a base case and need to return. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case: head is null or head next is null
        if ((head == NULL) || (head->next == NULL)) {
            return head;
        }
        
        // get the two nodes we wish to swap
        ListNode* front = head;
        ListNode* back = front->next;
        
        // swap them
        front->next = back->next;
        back->next = front;
        
        // call swapPairs on the next node (keep track of previous node as well)
        swapPairs(front->next, front);
        
        // return the new head of the list
        return back;
    }
    
    void swapPairs(ListNode* head, ListNode* before) {
        // base case: head is null or head next is null
        if ((head == NULL) || (head->next == NULL)) {
            return;
        }
        
        // get the two nodes we wish to swap
        ListNode* front = head;
        ListNode* back = front->next;
        
        // swap them
        front->next = back->next;
        back->next = front;
        
        // point 'before' to the new front node
        before->next = back;
        
        // call swapPairs on the next node
        swapPairs(front->next, front);
        
        return;
    }
};