class Solution {
public:
    // dp[0] stores result when first element, nums[0] is included
    // dp[1] stores result wehn last element, nums[n-1] is included
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
        dp.resize(2,vector<int>(n,-1));
        // if nums[0] and nums[n-1] cannot be together
        // so we pass 2 different start and end
        // one is without first element, other is without last element
        return max(solve(nums,0,0,n-2), solve(nums,1,1,n-1));
    }
};