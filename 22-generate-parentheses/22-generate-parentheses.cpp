class Solution {
public:
    
    vector<string> res;
    
    void solve(int n, int count, string op){
        if(n==0){
            if(count==0)
                res.push_back(op);
            return;
        }
        // if count>0, only then add )
        solve(n-1,count+1,op+'(');
        if(count){
            solve(n-1,count-1,op+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string op;
        solve(2*n,0,op);
        return res;
    }
};