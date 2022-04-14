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
    // priority_queue<int,vector<int>,greater<>> pq;
    int res = 0;
    void inorder(TreeNode* root, int& i, int k){
        if(!root){
            return;
        }
        inorder(root->left,i,k);
        if(i==k){
            res = root->val;
        }
        i++;
        inorder(root->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int n = 1;
        inorder(root,n,k);
        return res;
    }
};