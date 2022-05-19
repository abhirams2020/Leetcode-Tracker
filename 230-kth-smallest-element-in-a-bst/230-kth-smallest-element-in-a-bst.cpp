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
    int ans;
    void inorder(TreeNode* root, int& count, int k){
        if(!root)
            return;
        inorder(root->left,count,k);
        if(count==k){
            ans = root->val;
        }
        count++;
        inorder(root->right,count,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 1;
        inorder(root,count,k);
        return ans;
    }
};