class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int> op, int index){
        if(index == nums.size()){
            res.push_back(op);
            return;
        }
        solve(nums, res, op, index+1);
        op.push_back(nums[index]);
        solve(nums, res, op, index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        solve(nums, res, op, 0);
        return res;
    }
};