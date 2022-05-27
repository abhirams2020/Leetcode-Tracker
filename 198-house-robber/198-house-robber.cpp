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
        return dp[index] = nums[index] + max(solve(nums,index+2), solve(nums,index+3));
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return max(solve(nums,0), solve(nums,1));
    }
};