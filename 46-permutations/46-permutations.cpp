class Solution {
public:
    
    void solve(vector<int>&nums, int start, vector<vector<int>> &res){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            solve(nums,start+1,res);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums,0,res);
        return res;
    }
};