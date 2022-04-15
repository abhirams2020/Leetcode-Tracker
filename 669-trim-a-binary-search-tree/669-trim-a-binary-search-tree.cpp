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
// class Solution {
// public:
    
//     TreeNode* deleteNode(TreeNode* root, int val){
//         if(root->val == val){
//             if(!root->left && !root->right){
//                 return NULL;
//             }
//             else if(root->left){
//                 return root->left;
//             }
//             else if(root->right){
//                 return root->right;
//             }
//             else {
                
//             }
//         }
//         else if(root->val > val){
//             deleteNode(root->left, val);
//         }
//         else {
//             deleteNode(root->right, val);
//         }
//     }
    
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
        
//     }
// };
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;
        
        if(root->val < low) {
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};