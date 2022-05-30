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
    // reverse linked list and return new head
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *prv = NULL, *cur = head, *nxt = head->next;
        while(cur){
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if(nxt!=NULL)
                nxt = nxt->next;
        }
        return prv;
    }
    
    void reorderList(ListNode* head) {
        // we need min 3 elements in list
        if(!head || !head->next || !head->next->next){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ptr = head;
        ListNode* revptr = reverseList(slow->next);
        slow->next = NULL;
        ListNode* nextptr;
        ListNode* nextrevptr;
        
        while(ptr && revptr && ptr!=revptr){
            nextptr = ptr->next;
            nextrevptr = revptr->next;
            ptr->next = revptr;
            revptr->next = nextptr;
            ptr = nextptr;
            revptr = nextrevptr;
        }
    }
};