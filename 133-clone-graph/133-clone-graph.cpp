/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // map to store new copy of an existing node
    // copies[old node of 1] returns new node of 1 if it exist
    unordered_map<Node*,Node*> copies;

    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        // if copy already has node, then we dont need to find its neighbours
        // if not, add all neighbours of old node to new node
        if(!copies.count(node)){
            copies[node] = new Node(node->val);
            for(auto i:node->neighbors){
                copies[node]->neighbors.push_back(cloneGraph(i));
            }
        }
        return copies[node];
    }
};