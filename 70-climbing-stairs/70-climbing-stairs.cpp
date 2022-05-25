class Solution {
public:
    
//     // RECURSIVE DP WITH MEMOIZATION
//     vector<int> dp;
    
//     int solve(int n){
//         if(n==0){
//             return 1;
//         }
//         if(n<0){
//             return 0;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         return dp[n] = solve(n-1) + solve(n-2);
//     }
    
//     int climbStairs(int n) {
//         // dp = vector<int> (n+1, -1);
//         dp.resize(n+1,-1);
//         int res =  solve(n);
//         return res;
//     }
    
    // ITERATIVE DP
    int climbStairs(int n) {
        // dp[i] shows how many ways to reach 0 from i
        // if we are in 0, 1 way to reach 0. ie no jump
        // if we are on 1, 1 way to reach 0, ie 1 jump
        
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<n+1;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};