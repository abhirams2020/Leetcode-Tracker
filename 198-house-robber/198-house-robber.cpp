class Solution {
public:
    vector<int> dp;
    
    int solve(vector<int> &nums, int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        return dp[index] = max(solve(nums,index+1), nums[index]+solve(nums,index+2));
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return solve(nums,0);
    }
};