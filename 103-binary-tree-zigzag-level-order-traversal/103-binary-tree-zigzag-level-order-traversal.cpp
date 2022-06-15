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
    // // BY REVERSING THE LEVEL AFTER GETTING ALL ELEMENTS
    
    // vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     if(!root){
    //         return res;
    //     }
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     // leftToRight indicates if we need to input elements in left to right order
    //     bool leftToRight = true;
    //     while(!q.empty()){
    //         int n = q.size();
    //         vector<int> temp(n);
    //         for(int i=0;i<n;i++){
    //             TreeNode *curr = q.front();
    //             if(leftToRight == true){
    //                 temp[i] = curr->val;
    //             }
    //             else {
    //                 temp[n-1-i] = curr->val;
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
        // use deque to access the queue elements in reverse order for right to left traversal
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool leftToRight = true;
        while(!dq.empty()){
            int n = dq.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                // if leftToRight is true, do same steps as normal level order traversal
                if(leftToRight == true){
                    TreeNode *curr = dq.front();
                    temp.push_back(curr->val);
                    if(curr->left)
                        dq.push_back(curr->left);
                    if(curr->right)
                        dq.push_back(curr->right);
                    dq.pop_front();
                }
                // if leftToRight is false, reverse the steps of normal level order traversal
                // i.e change front to back, left to right etc
                else {
                    TreeNode *curr = dq.back();
                    temp.push_back(curr->val);
                    if(curr->right)
                        dq.push_front(curr->right);
                    if(curr->left)
                        dq.push_front(curr->left);
                    dq.pop_back();
                }
            }
            res.push_back(temp);
            leftToRight = !leftToRight;
        }
        return res;
    }
};