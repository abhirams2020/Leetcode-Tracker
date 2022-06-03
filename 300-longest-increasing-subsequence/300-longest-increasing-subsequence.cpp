class Solution {
public:
    int dp[2501][2502];
    
    int solve(vector<int> &nums, int index, int prev_i){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][prev_i+1]!=-1){
            return dp[index][prev_i+1];
        }
        int include = 0, notInclude = 0;
        if(prev_i==-1 || nums[index]>nums[prev_i]){
            include = 1 + solve(nums,index+1,index);
        }
        notInclude = solve(nums,index+1,prev_i);
        return dp[index][prev_i+1] = max(include, notInclude);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // dp.resize(nums.size(), vector<int>(1+nums.size(),-1));
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
    }
};