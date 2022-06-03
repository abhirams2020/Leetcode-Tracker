class Solution {
public:
    vector<vector<int>> dp;
    
    bool targetSum(vector<int> &nums, int index, int sum) {
        if(sum == 0){
            return true;
        }
        if(index == nums.size()){
            return false;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        bool include = false, notInclude = false;
        if(nums[index] <= sum){
            include = targetSum(nums,index+1,sum-nums[index]);
        }
        notInclude = targetSum(nums,index+1,sum);
        return dp[index][sum] = (include || notInclude);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        // if sum is odd, it cannot be partitioned into 2
        if(sum%2 == 1){
            return false;
        }
        // we have to find subsequence with sum = sum/2
        dp.resize(nums.size(), vector<int> (1+(sum/2), -1));
        return targetSum(nums, 0, sum/2);
    }
};