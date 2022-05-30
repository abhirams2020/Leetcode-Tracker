/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // check if a string is number
    bool isNumber(string str){
        for(auto i:str){
            if(!isdigit(i)){
                return false;
            }
        }
        return true;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "NULL,";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    TreeNode* decode(queue<string> &q){
        // q will never be empty. if tree is [], q = {"NULL"}
        string rootVal = q.front();
        q.pop();
        if(rootVal=="NULL"){
            return NULL;
        }
        TreeNode* root = new TreeNode();
        root->val = stoi(rootVal);
        root->left = decode(q);
        // decode(q) above will pop all values to left of root
        root->right = decode(q);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        string curr;
        queue<string> nodes;
        while(index<data.size()){
            if(data[index]==','){
                nodes.push(curr);
                curr = "";
            }
            else {
                curr.push_back(data[index]);
            }
            index++;
        }
        return decode(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));