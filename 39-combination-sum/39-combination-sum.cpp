// class Solution {
// public:
//     vector<vector<int>> res;
    
//     void solve(vector<int> &candidates, int index, vector<int> op, int target){
//         if(target==0){
//             res.push_back(op);
//             return;
//         }
//         if(index==candidates.size()){
//             return;
//         }
//         if(candidates[index] <= target){
//             solve(candidates,index+1,op,target);
//             op.push_back(candidates[index]);
//             solve(candidates,index,op,target-candidates[index]);
//         }
//         // else{
//         //     solve(candidates,index+1,op,target);
//         // }
//     }
    
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> op;
//         sort(candidates.begin(),candidates.end());
//         solve(candidates,0,op,target);
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> &candidates, int index, vector<int> op, int target){
        if(target==0){
            res.push_back(op);
            return;
        }
        if(index==candidates.size() || target<candidates[index]){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            op.push_back(candidates[i]);
            solve(candidates,i,op,target-candidates[i]);
            op.pop_back();
        }
        // else{
        //     solve(candidates,index+1,op,target);
        // }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,op,target);
        return res;
    }
};