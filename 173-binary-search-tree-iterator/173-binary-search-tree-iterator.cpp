/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    
    vector<int> inorder;
    int index = 0;
    
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            dfs(root->left);
        }
        cout<<root->val<<" ";
        inorder.push_back(root->val);
        cout<<inorder[inorder.size()-1]<<endl;
        if(root->right){
            dfs(root->right);
        }        
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        if(index == inorder.size()){
            return -1;
        }
        int res = inorder[index];
        index++;
        return res;
    }
    
    bool hasNext() {
        return index != inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */