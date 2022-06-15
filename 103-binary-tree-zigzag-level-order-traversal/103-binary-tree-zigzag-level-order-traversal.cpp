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
    // // REVERSING THE LEVEL AFTER GETTING ALL ELEMENTS
    // vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     if(!root){
    //         return res;
    //     }
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     bool leftToRight = false;
    //     while(!q.empty()){
    //         int n = q.size();
    //         vector<int> temp(n);
    //         for(int i=0;i<n;i++){
    //             TreeNode *curr = q.front();
    //             if(leftToRight == true){
    //                 temp[n-1-i] = curr->val;
    //             }
    //             else {
    //                 temp[i] = curr->val;
    //             }
    //             if(curr->left)
    //                 q.push(curr->left);
    //             if(curr->right)
    //                 q.push(curr->right);
    //             q.pop();
    //         }
    //         res.push_back(temp);
    //         leftToRight = !leftToRight;
    //     }
    //     return res;
    // }
    
    // REVERSING ORDER OF ADDING ELEMENTS IN QUEUE
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        bool leftToRight = false;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(leftToRight == false){
                    TreeNode *curr = q.front();
                    temp.push_back(curr->val);
                    if(curr->left)
                        q.push_back(curr->left);
                    if(curr->right)
                        q.push_back(curr->right);
                    q.pop_front();
                }
                else {
                    TreeNode *curr = q.back();
                    temp.push_back(curr->val);
                    if(curr->right)
                        q.push_front(curr->right);
                    if(curr->left)
                        q.push_front(curr->left);
                    q.pop_back();
                }
            }
            res.push_back(temp);
            leftToRight = !leftToRight;
        }
        return res;
    }
};