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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }
        ListNode* dummy=new ListNode(0), *curr=head;
        dummy->next = curr;
        ListNode* prev = dummy;
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
                curr = prev->next;
            }
            else{
                prev = prev->next;
                if(curr)
                    curr = curr->next;                
            }

        }
        return dummy->next;
    }
};