// This solution runs in O(n) time and has O(n) space complexity. It essentially works by having a while loop that goes through both lists at the same time,
// adding in the lesser node of the two lists to our return list and incrementing that list's pointer. This isn't my favorite solution, because it looks a bit ugly and 
// unintuitive, so solution 2 uses recursion. 

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // create a new list for the return
        int iterations = 0;
        ListNode* curr = nullptr;
        ListNode* head = nullptr;
        int list1val;
        int list2val;
        while (list1 || list2) { // still nodes to add
            if (list1) list1val = list1->val; // get values of list1 and list2 nodes
            else list1val = 101;
            if (list2) list2val = list2->val;
            else list2val = 101;
            
            ListNode* newNode = new ListNode(); // create new node
            if (list1val <= list2val) { // fill it's value
                newNode->val = list1val;
                list1 = list1->next;
            }
            else {
                newNode->val = list2val;
                list2 = list2->next;
            }
            
            if (!head) { // set the head if it hasn't been set
                head = newNode;
                curr = head;
            }
            else { // otherwise just add in the new node
                curr->next = newNode;
                curr = curr->next;
            }
            
            
        }
        return head;
        
    }
};