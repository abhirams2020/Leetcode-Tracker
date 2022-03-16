class Solution {
public:
    int climbStairs(int n) {
        vector<int> count(n+1,0);
        count[0] = 1;
        count[1] = 1;
        for(int i=2;i<=n;i++){
            count[i] = count[i-1] + count[i-2];
        }
        return count[n];
    }
//     int dp[46];
//     int solve(int n){
//         if(n<0){
//             return 0;
//         }
//         if(n==0){
//             return 1;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         return dp[n]=solve(n-1) + solve(n-2);        
//     }

//     int climbStairs(int n) {
//         memset(dp,-1,sizeof(dp));
//         return solve(n);
//     }
};