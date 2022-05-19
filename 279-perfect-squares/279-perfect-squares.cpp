class Solution {
public:
    vector<int> dp;
    
    int check(int sum){
        if(sum==0){
            return 0;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int res = INT_MAX;
        for(int i=1;i*i<=sum;i++){
            res = min(res, 1+check(sum-i*i));
        }
        dp[sum] = res;
        return res;
    }
    
    int numSquares(int n) {
        dp.resize(n+1,-1);
        int ans = check(n);
        return ans;
    }
};