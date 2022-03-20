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
    
    bool searchTree(TreeNode* root, int num){
        if(!root){
            return false;
        }
        if(root->val == num){
            return true;
        }
        return searchTree(root->left,num) || searchTree(root->right,num);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(searchTree(root->left,p->val) && searchTree(root->left,q->val)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(searchTree(root->right,p->val) && searchTree(root->right,q->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};