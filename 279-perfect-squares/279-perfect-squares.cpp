class Solution {
public:
    unordered_map<int,int> dp;
    
    int check(int sum){
        if(sum==0){
            return 0;
        }
        if(sum<0){
            return INT_MAX;
        }
        if(dp.count(sum)){
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
        int ans = check(n);
        return ans;
    }
};