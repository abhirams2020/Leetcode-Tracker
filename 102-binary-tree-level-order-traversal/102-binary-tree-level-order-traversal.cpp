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
    
    // // PUSHING NULL POINTER FOR EACH LEVEL
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> ans;
    //     if(!root){
    //         return ans;
    //     }
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     q.push(NULL);
    //     vector<int> temp;
    //     while(!q.empty()){
    //         TreeNode* curr = q.front();
    //         q.pop();
    //         if(curr == NULL){
    //             ans.push_back(temp);
    //             temp.clear();
    //             if(!q.empty())
    //                 q.push(NULL);
    //         }
    //         else {
    //             if(curr->left)
    //                 q.push(curr->left);
    //             if(curr->right)
    //                 q.push(curr->right);
    //             temp.push_back(curr->val);
    //         }
    //     }
    //     return ans;
    // }
    
    // STORE SIZE OF PARENT AND WITH FOR LOOP PUSH CHILDREN INTO QUEUE
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                temp.push_back(curr->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};