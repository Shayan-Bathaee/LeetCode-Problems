// This solution runs in O(n) time and has O(1) space complexity. It works by iterating through the linked list, and keeping track of the current node
// and its previous node. It makes each node point to the previous one, such that at the end every node points the oppisite direction. The last node is 
// returned as the head of the reversed linked list.

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
    ListNode* reverseList(ListNode* head) {
        // base case, empty list
        if (!head) {
            return NULL;
        }
        
        // iterate through list, making each node point to it's previous
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            head = curr;
            curr = curr->next;
            head->next = prev;
            prev = head;
        }
        return head;
    }
};