class Solution {
public:
    
    void solve(vector<int>&nums, int start, set<vector<int>> &res){
        if(start==nums.size()){
            res.insert(nums);
            return;
        }
        
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            solve(nums,start+1,res);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        solve(nums,0,s);
        vector<vector<int>> res;
        for(auto i:s){
            res.push_back(i);
        }
        return res;
    }
};