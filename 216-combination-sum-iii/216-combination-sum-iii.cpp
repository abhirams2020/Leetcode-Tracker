class Solution {
public:
    vector<vector<int>> res;
    
    void solve(int n, int k, int curr, vector<int> op){
        if(n==0 and k==0){
            res.push_back(op);
            return;
        }
        if(k==0){
            return;
        }
        for(int i=curr;i<=9;i++){
            if(i>n){
                return;
            }
            op.push_back(i);
            solve(n-i,k-1,i+1,op);
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> op;
        solve(n,k,1,op);
        return res;
    }
};