class Solution {
public:
    void solve(vector<int> &nums,vector<int> op,int index,vector<vector<int>> &ans){
        ans.push_back(op);
        for(int i=index;i<nums.size();i++){
            if(i==index || nums[i]!=nums[i-1]){
                op.push_back(nums[i]);
                solve(nums,op,i+1,ans);
                op.pop_back();                 
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums,op,0,ans);
        return ans;
    }
};