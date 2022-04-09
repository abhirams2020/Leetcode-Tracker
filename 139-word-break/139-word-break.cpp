class Solution {
public:
    
    int dp[301];
    
    bool solve(string &s, int l, unordered_set<string> &dict){
        if(l==s.length()){
            return true;
        }
        if(dp[l]!=-1){
            return dp[l];
        }
        string str;
        for(int i=l;i<s.length();i++){
            str.push_back(s[i]);
            if(dict.count(str) && solve(s,i+1,dict)){
                return dp[i] = true;
            }
        }
        return dp[l] =false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> dict;
        for(auto i:wordDict){
            dict.insert(i);
        }
        return solve(s,0,dict);
    }
};