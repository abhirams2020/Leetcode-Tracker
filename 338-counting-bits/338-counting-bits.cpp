class Solution {
public:
    
    unordered_map<int,int> dp;
    
    int count1s(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        return dp[n] = count1s(n>>1) + (n%2);
    }
    
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(count1s(i));
        }
        cout<<count1s(5);
        return res;
    }
};