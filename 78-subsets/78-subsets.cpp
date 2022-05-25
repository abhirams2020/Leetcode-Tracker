class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int> op, int index){
        res.push_back(op);
        for(int i=index;i<nums.size();i++){
            op.push_back(nums[i]);
            solve(nums, res, op, i+1);
            op.pop_back();
        }

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        solve(nums, res, op, 0);
        return res;
    }
};