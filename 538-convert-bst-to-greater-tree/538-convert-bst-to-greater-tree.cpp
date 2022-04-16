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
    /*  
        use reverse inorder to calculate the sum greater than or equal to current
        after each step, increase sum and change root->val to sum
    */
//     int sum = 0;
//     void revinorder(TreeNode* root){
//         if(!root){
//             return;
//         }
//         revinorder(root->right);
    
//         sum+=root->val;
//         root->val = sum;
    
//         revinorder(root->left);
//     }
    
//     TreeNode* convertBST(TreeNode* root) {
//         revinorder(root);
//         return root;
//     }
    
    /*  
        use reverse inorder to calculate the sum greater than or equal to current
        after each step, increase sum and change root->val to sum
        
        wITHOUT HELPER FUNCTION
    */    
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return NULL;
        }
        if(root->right)
            root->right = convertBST(root->right);
        
        sum += root->val;
        root->val = sum;
        
        if(root->left)
            root->left = convertBST(root->left);
        return root;
    }
};