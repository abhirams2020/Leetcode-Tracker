class Solution {
public:
    void solve(vector<int> &nums,vector<int> op,int index,set<vector<int>> &res){
        res.insert(op);
        for(int i=index;i<nums.size();i++){
            if(i==index || nums[i]!=nums[i-1]){
                op.push_back(nums[i]);
                solve(nums,op,i+1,res);
                op.pop_back();                 
            }
        }
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