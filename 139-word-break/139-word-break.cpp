class Solution {
public:
    unordered_set<string> words;
    
    int dp[301];
    
    bool solve(string &s, int start, int end){
        if(start>end){
            return true;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        for(int i=start;i<=end;i++){
            if(words.count(s.substr(start,i-start+1)) && solve(s,i+1,end)){
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for(auto i:wordDict){
            words.insert(i);
        }
        return solve(s, 0, s.length()-1);
    }
};