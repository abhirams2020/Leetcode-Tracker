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
    bool isSameTree(TreeNode* a, TreeNode* b){
        if(!a and !b)
            return true;
        if(!a or !b)
            return false;
        return a->val==b->val && isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }
        return isSameTree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};