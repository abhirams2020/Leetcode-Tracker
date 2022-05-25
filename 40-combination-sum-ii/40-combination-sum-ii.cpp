class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> &nums, vector<int> op, int target, int index){
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
                solve(nums,op,target-nums[i],i+1);
                op.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> op;
        solve(candidates, op, target, 0);
        return res;
    }
};