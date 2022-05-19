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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int last = root->val;
        
        while(!q.empty()){
            int n = q.size();
            ans.push_back(last);
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    last = curr->left->val;
                }
                if(curr->right){
                    q.push(curr->right);
                    last = curr->right->val;
                }
            }
        }
        return ans;
    }
};