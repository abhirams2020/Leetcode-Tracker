class Solution {
public:
    vector<vector<string>> res;
    vector<vector<int>> dp;
    
    bool isPalindrome(string s, int left, int right){
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        while(left < right){
            if(s[left]!=s[right]){
                return dp[left][right] = 0;
            }
            left++;
            right--;
        }
        return dp[left][right] = 1;
    }
    
    void dfs(string s, vector<string> op, int index){
        if(index==s.length()){
            res.push_back(op);
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                op.push_back(s.substr(index, i-index+1));
                dfs(s, op, i+1);
                op.pop_back();                
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp = vector<vector<int>> (n,vector<int>(n,-1));
        vector<string> op;
        dfs(s,op,0);
        return res;
    }
};