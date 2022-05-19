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
    
    void preorder(TreeNode* root, int &count, int maxSoFar){
        if(!root)
            return;
        
        if(root->val >= maxSoFar){
            maxSoFar = root->val;
            count++;
        }
        
        preorder(root->left,count,maxSoFar);
        preorder(root->right,count,maxSoFar);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int count=0, maxSoFar = root->val;
        preorder(root,count,maxSoFar);
        return count;
    }
};