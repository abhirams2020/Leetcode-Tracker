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
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        
        // add sum of both to new nodes
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            // if sum >= 10, enter only unit digit in new list
            ListNode* newnode = new ListNode(sum%10);
            curr->next = newnode;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
            // update new carry
            if(sum>=10)
                carry = 1;
            else 
                carry = 0;
        }
        
        // if l1 or l2 still left, add those to new list
        while(l1){
            int sum = l1->val + carry;
            ListNode* newnode = new ListNode(sum%10);
            curr->next = newnode;
            curr = curr->next;
            l1 = l1->next;
            if(sum>=10)
                carry = 1;
            else 
                carry = 0;
        }
        
        while(l2){
            int sum = l2->val + carry;
            ListNode* newnode = new ListNode(sum%10);
            curr->next = newnode;
            curr = curr->next;
            l2 = l2->next;
            if(sum>=10)
                carry = 1;
            else 
                carry = 0;
        }
        
        // if still carry remains, add 1 to end of list. eg 9999 + 999 = 10998
        if(carry == 1){
            ListNode* newnode = new ListNode(1);
            curr->next = newnode;
        }
        
        return dummy->next;
    }
};