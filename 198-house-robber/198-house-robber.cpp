class Solution {
public:
    
    int dp[100];
    // int solve(vector<int> &nums, int index){
    //     if(index>=nums.size()){
    //         return 0;
    //     }
    //     if(dp[index]!=-1){
    //         return dp[index];
    //     }
    //     int mx = nums[index];
    //     for(int i=index;i<nums.size();i++){
    //         mx = max(mx,nums[i] + solve(nums,i+2));
    //     }
    //     return dp[index]=mx;
    // }
    
    int solve(vector<int> &nums, int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        // include nums[index] and move to index+2 OR not include nums[index] and move to index+1
        return dp[index] = max(solve(nums,index+1) ,nums[index] + solve(nums,index+2));
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};