class Solution {
public:
    void solve(vector<int> &nums,vector<int> op,int index,set<vector<int>> &res){
        if(index==nums.size()){
            res.insert(op);
            return;
        }
        solve(nums,op,index+1,res);
        op.push_back(nums[index]);
        solve(nums,op,index+1,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums,op,0,res);
        
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
};