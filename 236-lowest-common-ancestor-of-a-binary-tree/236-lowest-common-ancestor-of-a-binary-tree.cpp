/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool searchBT(TreeNode* root, TreeNode* n){
        if(!root){
            return false;
        }
        return root==n || searchBT(root->left,n) || searchBT(root->right,n);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(searchBT(root,p) && searchBT(root,q) && !l && !r){
            return root;
        }
        if(l)
            return l;
        return r;
    }
};