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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }
        ListNode *slow=head, *fast=head;
        // move fast n times.
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        // if n is equal to size of LL, we need to remove first node
        if(fast == NULL){
            return head->next;
        }
        // when fast has been moved n times, move both slow and fast
        // when fast reaches end of LL, slow will reach previous of node to be deleted.
        while(fast && fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};