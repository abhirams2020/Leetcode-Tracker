class Solution {
public:
    
    
    void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> op, int target, int index){
        if(target == 0){
            res.push_back(op);
            return;
        }
        if(index==nums.size() || nums[index]>target){
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(nums[i]<=target && (i==index || nums[i]!=nums[i-1])){
                op.push_back(nums[i]);
                solve(nums,res,op,target-nums[i],i+1);
                op.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> op;
        
        sort(candidates.begin(), candidates.end());

        solve(candidates, res, op, target, 0);
        return res;
    }
};