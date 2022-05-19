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
    
    void preorder(TreeNode* root,int &n, int maxVal){
        if(!root)
            return;
        
        if(root->val >= maxVal){
            maxVal = root->val;
            n++;
        }
        
        preorder(root->left,n,maxVal);
        preorder(root->right,n,maxVal);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int n=0, maxVal = root->val;
        preorder(root,n,maxVal);
        return n;
    }
};