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
private:
    unordered_map<int,int> findIndexInorder;
public:
    
    // // using preleft and preright to indicate start and end index of preorder vector
    
    // TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
    //     if(inleft>inright){
    //         return NULL;
    //     }
    //     int curr = preorder[preleft];
    //     TreeNode* newnode = new TreeNode(curr);
    //     int index=inleft;
    //     while(inorder[index]!=curr){
    //         index++;
    //     }
    //     int leftTreeSize = index-inleft;
    //     int rightTreeSize = inright-index;
    //     newnode->left = build(preorder, inorder, preleft+1, preleft+leftTreeSize, inleft, index-1);
    //     newnode->right = build(preorder, inorder, preleft+1+leftTreeSize, preright, index+1, inright);
    //     return newnode;
    // }
    
    
    // using rootIndex to indicate pos of root index in preorder vector
    // rootIndex follows preorder traversal and increases after each node is visited
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &preorderIndex, int inleft, int inright){
        if(inleft>inright){
            return NULL;
        }
        int curr = preorder[preorderIndex];
        TreeNode* newnode = new TreeNode(curr);
        
        int index=findIndexInorder[curr];
        // after visiting each node in preorder traversal, increment preorderIndex
        preorderIndex++;
        //preorderIndex value gets changed after successive calls to build the left subtree
        //Since it is passed as reference, updated value of preorderIndex is passed to build
        //the right subtree
        newnode->left = build(preorder, inorder, preorderIndex, inleft, index-1);
        newnode->right = build(preorder, inorder, preorderIndex, index+1, inright);
        return newnode;
    }

    // *Intuition* : First in preorder will be root. Find pos of root in inorder. 
    // Elements left to inorder is left of root, right to inorder is right of root
    // To find root->left, make new inorder as 0 to index-1 of present inorder.
    // New preorder should be from range 1 to size of new left inorder
    // Similar process for finding root->right. Then return root.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            findIndexInorder[inorder[i]] = i;
        }
        int preorderIndex = 0;
        return build(preorder, inorder, preorderIndex, 0, n-1);
    }
};