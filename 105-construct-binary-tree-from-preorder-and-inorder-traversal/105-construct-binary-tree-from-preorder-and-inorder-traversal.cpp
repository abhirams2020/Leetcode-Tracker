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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIndex, int inleft, int inright){
        if(inleft>inright){
            return NULL;
        }
        int curr = preorder[rootIndex];
        TreeNode* newnode = new TreeNode(curr);
        
        int index=inleft;
        while(inorder[index]!=curr){
            index++;
        }
        rootIndex++;
        newnode->left = build(preorder, inorder, rootIndex, inleft, index-1);
        newnode->right = build(preorder, inorder, rootIndex, index+1, inright);
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int rootIndex = 0;
        return build(preorder, inorder, rootIndex, 0, n-1);
    }
};