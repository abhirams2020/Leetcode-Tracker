class Solution {
public:
    vector<vector<int>> res;
    
    void solve(int n, int curr, int k, vector<int> op){
        if(op.size()==k){
            res.push_back(op);
            return;
        }
        // if(n-curr+1<k-op.size()){
        //     return;
        // }
        if(curr>n){
            return;
        }
        
        for(int i=curr;i<=n;i++){
            op.push_back(i);
            solve(n, i+1, k, op);
            op.pop_back();
        }
    }
    
//     void solve(int n, int curr, int k, vector<int> op){
//         if(op.size()==k){
//             res.push_back(op);
//             return;
//         }
//         if(n-curr+1<k-op.size()){
//             cout<<curr<<" "<<op.size()<<endl;
//             return;
//         }
//         if(curr>n){
//             return;
//         }

//         solve(n, curr+1, k, op);
//         op.push_back(curr);
//         solve(n, curr+1, k, op);
//     }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> op;
        solve(n,1,k,op);
        return res;
    }
};