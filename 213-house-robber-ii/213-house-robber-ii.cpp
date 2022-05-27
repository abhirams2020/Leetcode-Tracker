class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int> &nums, int dpIndex, int index, int end){
        if(index > end){
            return 0;
        }
        if(dp[dpIndex][index] != -1){
            return dp[dpIndex][index];
        }
        return dp[dpIndex][index] = max(solve(nums,dpIndex,index+1,end), nums[index] + solve(nums,dpIndex,index+2,end));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        dp.resize(2,vector<int>(n+1,-1));
        int res = max(solve(nums,0,0,n-2), solve(nums,1,1,n-1));
        return res;
    }
};