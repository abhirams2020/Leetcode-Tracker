class Solution {
public:
    vector<string> ans;
    
    void solve(int n, int open, int close, string s){
        if(s.size()==2*n){
            if(open==close)
                ans.push_back(s);
            return;
        }
        if(open<=n){
            solve(n,open+1,close,s+'(');
            if(open>close){
                solve(n,open,close+1,s+')');
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return ans;
    }
};