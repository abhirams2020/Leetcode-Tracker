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
    int findLen(ListNode* head){
        ListNode* curr = head;
        int len=0;
        while(curr){
            len++;
            curr = curr->next;
        }
        return len;
    }
    
    // n is no of remaining nodes in list. k is size of rotation group.
    ListNode* reverse(ListNode* head, int n, int k){
        if(!head || !head->next){
            return head;
        }
        // ListNode* temp=head;
        // for(int i=0;i<k;i++){
        //     if(temp==NULL){
        //         return head;
        //     }
        //     temp = temp->next;
        // }
        if(n<k){
            return head;
        }
        ListNode *prv=NULL, *cur=head, *nxt=head->next;
        for(int i=0;i<k;i++){
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if(nxt){
                nxt = nxt->next;
            }
        }
        head->next = reverse(cur, n-k, k);
        return prv;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = findLen(head);
        ListNode *newHead = reverse(head, n, k);
        return newHead;
    }
};