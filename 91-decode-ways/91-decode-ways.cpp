class Solution {
public:
    
    int dp[101];
        
    int solve(string& s, int idx){
        if(idx == s.length()){
            return 1;
        }
        if(s[idx]=='0'){
            return 0; // sub string starting with 0 is not a valid encoding
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int ans = 0;
        ans += solve(s, idx+1);
        if(idx < s.length()-1 && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6'))){
            ans += solve(s, idx+2);
        }
        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};