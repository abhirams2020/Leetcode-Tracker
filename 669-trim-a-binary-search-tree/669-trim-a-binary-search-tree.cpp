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
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root){
            return NULL;
        }
        if(root->val < low){
            return trimBST(root->right, low, high);
        }
        if(root->val > high){
            return trimBST(root->left, low, high);
        }
        root->right = trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        return root;
    }
        
    /*  if root less than low, root of result should be trimBST(root->right)
        if no root greater than low, it returns NULL

        if root greater than high, root of result should be trimBST(root->left)
        if no root less than high, it returns NULL

        if root between low and high, it is valid root
        root->left and root->right should be also valid, so use trimBST
    */

};