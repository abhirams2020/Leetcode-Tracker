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
        ListNode* start=new ListNode(0), *curr=head;
        start->next = curr;
        ListNode* prev = start;
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
                ListNode* temp=curr;
                delete temp;
                curr = prev->next;
            }
            else{
                prev = prev->next;
                if(curr)
                    curr = curr->next;                
            }

        }
        return start->next;
    }
};