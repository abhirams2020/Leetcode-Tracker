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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* min1 = list1, *min2 = list2, *dummy = new ListNode(0), *temp;
        temp = dummy;
        while(min1 && min2){
            if(min1->val < min2->val){
                temp->next = min1;
                min1 = min1->next;
            }
            else {
                temp->next = min2;
                min2 = min2->next;
            }
            temp = temp->next;
        }
        if(min1)
            temp->next = min1;
        if(min2)
            temp->next = min2;
        return dummy->next;
    }
};