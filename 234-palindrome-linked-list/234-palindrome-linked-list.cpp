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
    // // array solution
    // bool isPalindrome(ListNode* head) {
    //     if(!head){
    //         return true;
    //     }
    //     vector<int> arr;
    //     ListNode* temp = head;
    //     while(temp){
    //         arr.push_back(temp->val);
    //         temp = temp->next;
    //     }
    //     int l = 0, r=arr.size()-1;
    //     while(l<r){
    //         if(arr[l]!=arr[r]){
    //             return false;
    //         }
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    
    ListNode* reverseLL(ListNode* head){
        if(!head)
            return head;
        ListNode* prv = NULL, *cur = head, *nxt = head->next;
        while(cur){
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if(nxt)
                nxt = nxt->next;
        }
        return prv;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head){
            return true;
        }
        ListNode *slow = head, *fast = head;
        ListNode* beforeMid = new ListNode(0);
        beforeMid->next = slow;
        while(fast && fast->next){
            beforeMid = beforeMid->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        beforeMid->next = NULL;
        ListNode *mid = slow;
        ListNode *midhead = reverseLL(mid);
        while(midhead && head){
            if(midhead->val != head->val){
                return false;
            }
            midhead = midhead->next;
            head = head->next;
        }
        return true;
    }
};