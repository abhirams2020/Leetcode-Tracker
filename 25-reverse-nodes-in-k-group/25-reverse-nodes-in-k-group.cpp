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
    // calculate total length of list
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
        // if size of list <= 1, we cannot reverse it. so return head
        if(!head || !head->next){
            return head;
        }
        // if no of elements remaining in list < k, we cannot reverse in k size group.
        if(n<k){
            return head;
        }
        // reverse k nodes from head ptr.
        ListNode *prv=NULL, *cur=head, *nxt=head->next;
        for(int i=0;i<k;i++){
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        // after reversing, head is end of list and prev is start of list
        // head->next will point to start of the next k grouped list with cur ptr as head
        head->next = reverse(cur, n-k, k);
        return prv;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = findLen(head);
        return reverse(head, n, k);
    }
};