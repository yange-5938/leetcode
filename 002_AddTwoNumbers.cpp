// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        // ListNode* node = new ListNode(0);
        ListNode head{0};
        ListNode* node = &head;

        while (l1 || l2 || carry){
            // int sum = l1->val + l2->val;
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (carry ? 1 : 0);
            carry = sum >= 10;

            // create a new node for the result
            ListNode* resultNode = new ListNode (sum % 10);
            
            node->next = resultNode;
            node = node->next;

            // move to next digit
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head.next;
    }

};
