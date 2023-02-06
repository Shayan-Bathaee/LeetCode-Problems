// This solution runs in O(n) time. It loops through both linked lists, and takes the sum of each digit at a time,
// exactly like how you would do regular long addition. 

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
#include <string>
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int carry = 0;

        // loop through the linked lists
        while (1) {
            // add the digit we are at
            if (l1 == nullptr) {
                curr->val = l2->val + carry;
            }
            else if (l2 == nullptr) {
                curr->val = l1->val + carry;
            }
            else {
                curr->val = l1->val + l2->val + carry;
            }
            
            // handle carry value
            if (curr->val >= 10) {
                curr->val = curr->val % 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            
            // move to next node if possible
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

            // if we have reached the end of both lists
            if ((l1 == nullptr) && (l2 == nullptr)) {
                // add in carry if possible and break
                if (carry) {
                    ListNode* newNode = new ListNode(1);
                    curr->next = newNode;
                    curr = newNode;
                }
                break;
            }

            // create a new node to store next digit's sum
            ListNode* newNode = new ListNode();
            curr->next = newNode;
            curr = newNode;
        }
        return head;
    }
};