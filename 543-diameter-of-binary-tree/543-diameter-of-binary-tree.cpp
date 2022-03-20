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
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        // The length of a path between two nodes is represented by the number of edges between them.
        int currDiameter = maxDepth(root->left) + maxDepth(root->right);
        int childDiameter = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(currDiameter, childDiameter);
    }
};