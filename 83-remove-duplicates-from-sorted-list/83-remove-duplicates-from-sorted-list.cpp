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
        ListNode* dummy = new ListNode(-101), *curr = head, *prev;
        dummy->next = curr;
        prev = dummy;
        while(curr){
            if(prev->val == curr->val){
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