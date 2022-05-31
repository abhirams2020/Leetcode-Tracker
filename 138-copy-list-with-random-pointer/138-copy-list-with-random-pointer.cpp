/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node* curr = head;
        while(curr){
            Node *temp = new Node(curr->val);
            mp[curr] = temp;
            curr = curr->next;
        }
        
        for(auto node:mp){
            (node.second)->next = mp[(node.first)->next];
            (node.second)->random = mp[(node.first)->random];
        }
        
        return mp[head];
    }
};