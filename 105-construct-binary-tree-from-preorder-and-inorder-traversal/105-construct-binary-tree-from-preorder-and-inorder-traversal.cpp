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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
        if(inleft>inright){
            return NULL;
        }
        int curr = preorder[preleft];
        TreeNode* newnode = new TreeNode(curr);
        int index;
        for(int i=inleft;i<=inright;i++){
            if(inorder[i]==curr){
                index=i;
                break;
            }
        }
        int leftTreeSize = index-inleft;
        int rightTreeSize = inright-index;
        newnode->left = solve(preorder, inorder, preleft+1, preleft+leftTreeSize, inleft, index-1);
        newnode->right = solve(preorder, inorder, preleft+1+leftTreeSize, preright, index+1, inright);
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
    }
};