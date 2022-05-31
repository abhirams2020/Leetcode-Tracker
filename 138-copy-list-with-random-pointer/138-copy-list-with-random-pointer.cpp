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
        // create a mapping of old node to new nodes
        map<Node*,Node*> mp;
        Node* curr = head;
        while(curr){
            Node *temp = new Node(curr->val);
            mp[curr] = temp;
            curr = curr->next;
        }
        
        // assign next and random similar to original list
        curr = head;
        mp[NULL] = NULL;
        while(curr){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        
        return mp[head];
    }
};