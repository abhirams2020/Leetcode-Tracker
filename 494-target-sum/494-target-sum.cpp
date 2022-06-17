class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int> &nums, int target, int index){
        if(target == 0 && index == nums.size()){
            // cout<<index<<endl;
            return 1;
        }
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][1000+target]!=-1){
            return dp[index][1000+target];
        }
        if(nums[index]<=target){            
            return dp[index][1000+target] = solve(nums,target,index+1) + solve(nums,target-nums[index],index+1);
        }
        return dp[index][1000+target] = solve(nums,target,index+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int diff) {
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        if(diff>sum || (sum+diff)%2 == 1){
            return 0;
        }
        int target = (sum+diff)/2;
        dp.resize(nums.size()+1, vector<int> (1000+target+1,-1));
        int ans = solve(nums,target,0);
        return ans;
    }
};