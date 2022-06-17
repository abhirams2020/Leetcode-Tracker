class Solution {
public:
    // int dp[21][2001];
    vector<vector<int>> dp;
    
    int solve(vector<int> &nums, int target, int index){
        if(target==0 and index == nums.size()){
            return 1;
        }
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][1000+target]!=-1){
            return dp[index][1000+target];
        }
        if(nums[index]<=target)
            return dp[index][1000+target] = solve(nums,target-nums[index],index+1) + solve(nums,target,index+1);
        return dp[index][1000+target] = solve(nums,target,index+1);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int diff) {
        // A + B = sum
        // A - B = diff
        // Find target = (sum+target)/2 from the nums. add +1 when subsequence found
        // same as target sum problem but elements can be 0 and target sum can be -ve
        // if target is negative, we cannot call dp[i][target]. so add 1000 to target each time we call
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        // if sum+diff is odd, it means subset satisfying the conds cannot be found, so count = 0
        if((sum+diff)%2 != 0){
            return 0;
        }
        int target = (sum+diff)/2;
        // memset(dp,-1,sizeof(dp));
        dp.resize(nums.size()+1, vector<int>(1000+target+1, -1));
        int ans = solve(nums,target,0);
        return ans;
    }
};