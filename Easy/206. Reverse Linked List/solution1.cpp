// This solution runs in O(n) time and has O(n) space complexity. It iterates through the linked list, pushing each element onto a stack. 
// Then, it pops each element off the stack, and appends it to a new linked list. The head of the new linked list is returned. 

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
        
        // create a stack and push each node onto the stack
        ListNode* curr = head;
        stack<int> nodes;
        while (curr) {
            nodes.push(curr->val);
            curr = curr->next;
        }
        
        // pop each element from stack into new linked list
        ListNode* result = new ListNode(nodes.top());
        nodes.pop();
        curr = result;
        while (!nodes.empty()) {
            ListNode* newNode = new ListNode(nodes.top());
            curr->next = newNode;
            curr = curr->next;
            nodes.pop();
        }
        return result;
    }
};