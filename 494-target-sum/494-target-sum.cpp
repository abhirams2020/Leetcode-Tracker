class Solution {
public:
    int dp[21][2000];
    
    int solve(vector<int> &nums, int sum, int target, int index){
        if(sum == target and index == nums.size()){
            cout<<index<<endl;
            return 1;
        }
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][1000+sum]!=-1){
            return dp[index][1000+sum];
        }
        return dp[index][1000+sum] = solve(nums,sum-nums[index],target,index+1) + solve(nums,sum+nums[index],target,index+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,target,0);
        return ans;
    }
};