class Solution {
public:
//     // using 2D dp memoization
//     vector<vector<int>> dp;
    
//     int solve(vector<int> &nums, int index, int prev_i){
//         if(index==nums.size()){
//             return 0;
//         }
//         if(dp[index][prev_i+1]!=-1){
//             return dp[index][prev_i+1];
//         }
//         int include = 0, notInclude = 0;
//         if(prev_i==-1 || nums[index]>nums[prev_i]){
//             include = 1 + solve(nums,index+1,index);
//         }
//         notInclude = solve(nums,index+1,prev_i);
//         return dp[index][prev_i+1] = max(include, notInclude);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         dp.resize(nums.size(), vector<int>(1+nums.size(),-1));
//         int ans =  solve(nums,0,-1);
//         for(auto i:dp){
//             for(auto j:i){
//                 cout<<j<<"\t";
//             }
//             cout<<endl;
//         }
//         return ans;
//     }
    
    // using 1D dp memoization
    
    // For a given prev index, every LIS to right is considered. So only prev index enough for dp
    // We should return dp[0] & prev index = -1, which considers elements from 0 to n-1.
    vector<int> dp;
    
    int solve(vector<int> &nums, int index, int prev_i){
        if(index==nums.size()){
            return 0;
        }
        if(dp[prev_i+1]!=-1){
            return dp[prev_i+1];
        }
        int include = 0, notInclude = 0;
        if(prev_i==-1 || nums[index]>nums[prev_i]){
            include = 1 + solve(nums,index+1,index);
        }
        notInclude = solve(nums,index+1,prev_i);
        return dp[prev_i+1] = max(include, notInclude);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(1+nums.size(),-1);
        int ans =  solve(nums,0,-1);
        return ans;
    }
};