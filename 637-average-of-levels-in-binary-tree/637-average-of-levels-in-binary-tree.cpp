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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            double sum = 0;
            int n = q.size();
            int count = n;
            while(n){
                TreeNode* p = q.front();
                sum+=(p->val);
                q.pop();
                n--;
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res.push_back(sum/count);
        }
        return res;
    }
};