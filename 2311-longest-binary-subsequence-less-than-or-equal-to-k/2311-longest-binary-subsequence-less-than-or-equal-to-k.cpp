class Solution {
public:
//     // BRUTE FORCE APPROACH
    int solve(string s, int index, int sum){
        int len = 0;
        int p = 0;
        for(int i=index;i<s.length();i++){
            int val = s[i]-'0';
            long double curr = pow(2,p);
            if(val==1 && curr<=sum){
                sum-=curr;
                len++;
            }
            else if(val==0){
                len++;
            }
            p++;
        }
        return len;
    }
    
    int longestSubsequence(string s, int sum) {
        reverse(s.begin(),s.end());
        int ans = 0;
        for(int i=0;i<s.length();i++){
            ans = max(ans, solve(s,i,sum));
        }
        return ans;
    }
    
//     // USING DP (not sure how its not 3D dp)
//     vector<vector<int>> dp;
    
//     int solve(string &s, int sum, int len, int index){
//         if(index==s.length()){
//             return 0;
//         }
//         if(dp[len][index]!=-1){
//             return dp[len][index];
//         }
//         int val = s[index]-'0';
//         long double curr = val * pow(2,len);
//         int include = 0, not_include = 0;
//         if(curr <= sum){
//             include = 1 + solve(s,sum-curr,len+1,index+1);
//         }
//         not_include = solve(s,sum,len,index+1);
//         return dp[len][index] = max(include, not_include);
//     }
    
//     int longestSubsequence(string s, int k) {
//         int n = s.length();
//         dp.resize(n+1, vector<int> (n+1,-1));
//         reverse(s.begin(),s.end());
//         return solve(s,k,0,0);
//     }
};