// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

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
    ListNode* deleteDuplicates(ListNode* head) {
        return checkDup(head, head);
    }


    ListNode* checkDup(ListNode* head, ListNode* top){
        if (!head) {
            return top; 
        }else if(!head->next){
            return top;
        } else if(head->val ==  head->next->val) {
            head->next = head->next->next;
            return checkDup(head, top);
        }
        else return checkDup(head->next, top);
        
    }
};
