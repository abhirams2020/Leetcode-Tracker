class Solution {
public:
    void solve(vector<int>&nums, vector<int> op, int index, vector<vector<int>> &res){
        if(index==nums.size()){
            res.push_back(op);
            return;
        }
        solve(nums,op,index+1,res);
        op.push_back(nums[index]);
        solve(nums,op,index+1,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        vector<vector<int>> res;
        solve(nums,op,0,res);
        return res;
    }
};