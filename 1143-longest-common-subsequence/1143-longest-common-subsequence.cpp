class Solution {
public:
    // USING MEMOIZATION
    // dp[n1][n2] stores longest subsequence when index of s1 is n1-1 and s2 is n2-1
    vector<vector<int>> dp;
    
    int maxLCS(string &s1, string &s2, int n1, int n2){
        if(n1==0 || n2==0){
            return 0;
        }
        if(dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        if(s1[n1-1] == s2[n2-1]){
            return dp[n1][n2] = 1 + maxLCS(s1,s2,n1-1,n2-1);
        }
        return dp[n1][n2] = max(maxLCS(s1,s2,n1-1,n2), maxLCS(s1,s2,n1,n2-1));
    }
    
    int longestCommonSubsequence(string &text1, string &text2) {
        int n1 = text1.length(), n2 = text2.length();
        dp.resize(n1+1, vector<int>(n2+1, -1));
        return maxLCS(text1, text2, n1, n2);
    }
    
//     // USING TABULATION
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.length(), n2 = text2.length();
//         int dp[n1+1][n2+1];
//         for(int i=0;i<=n1;i++){
//             dp[i][0] = 0;
//         }
//         for(int j=0;j<=n2;j++){
//             dp[0][j] = 0;
//         }
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++){
//                 if(text1[i] == text2[j]){
//                     dp[i][j] = 1+dp[i-1][j-1];
//                 }
//                 else {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n1][n2];
//     }
};