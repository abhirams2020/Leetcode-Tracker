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
class Solution {
public:
    
    TreeNode* ans = new TreeNode();
    TreeNode* curr = ans;
    
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left)
            inorder(root->left);
        curr->right = new TreeNode(root->val);
        curr = curr->right;
        if(root->right)
            inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root){
            return NULL;
        }
        inorder(root);
        return ans->right;
    }
};