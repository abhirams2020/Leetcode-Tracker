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
//     // USING LEVEL ORDER TRAVERSAL. KEEPING TRACK OF LAST VALUE IN EVERY LEVEL
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if(!root)
//             return ans;
        
//         queue<TreeNode*> q;
//         q.push(root);
//         int last;
//         while(!q.empty()){
//             int n = q.size();
//             for(int i=0;i<n;i++){
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 if(i==n-1){
//                     cout<<curr->val;
//                     last = curr->val;
//                 }
//                 if(curr->left){
//                     q.push(curr->left);
//                 }
//                 if(curr->right){
//                     q.push(curr->right);
//                 }
//             }
//             ans.push_back(last);
//         }
//         return ans;
//     }
    
    // USING RIGHT TO LEFT PREORDER TRAVERSAL
    
    // if ans.size()==level, it means root is first element in the layer so far. 
    // since we are doing reverse preorder traversal the first element in the level will be rightmost.
    // push that element to result vector and increase level by 1
    void revPreorder(TreeNode* root, vector<int> &ans, int level) {
        if(!root)
            return;
        if(ans.size()==level){
            ans.push_back(root->val);
        }
        revPreorder(root->right, ans, level+1);
        revPreorder(root->left, ans, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        revPreorder(root,ans,level);
        return ans;
    }
};