class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(vector<int> &candidates, int target, int index, vector<int>& op){

        if(target == 0){
            res.push_back(op);
            return;
        }
        if(index==candidates.size()){
            return;
        }        
        if(candidates[index]>target){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]>target){
                return;
            }
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            op.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, op);
            op.pop_back();
        }

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> op;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,op);
        return res;
    }
    
};