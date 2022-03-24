class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> &candidates, int index, vector<int> op, int target){
        if(target==0){
            res.push_back(op);
            return;
        }
        if(target<0 || index==candidates.size()){
            return;
        }
        if(candidates[index] <= target){
            solve(candidates,index+1,op,target);
            op.push_back(candidates[index]);
            solve(candidates,index,op,target-candidates[index]);
        }
        else{
            solve(candidates,index+1,op,target);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op;
        solve(candidates,0,op,target);
        return res;
    }
};