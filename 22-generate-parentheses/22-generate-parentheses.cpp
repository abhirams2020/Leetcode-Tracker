class Solution {
public:
    vector<string> ans;
    
    // open represents number of opening brackets left, closed is number of closing bracket left
    void solve(int open, int close, string s){
        // when no more opening and closing to be added, push to ans
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        
        // if there is opening bracket left, add (
        if(open>0)
            solve(open-1,close,s+'(');
        
        // if number of closing bracket remaining than no of open, add )
        if(close>open){
            solve(open,close-1,s+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");
        return ans;
    }
};