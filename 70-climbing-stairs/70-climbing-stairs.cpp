class Solution {
public:
    unordered_map<int,int> dp;
    int count(int n){
        if(n==0){
            return 1;
        }
        else if(n<0){
            return 0;
        }
        else if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        return dp[n] = count(n-1) + count(n-2);
    }
    int climbStairs(int n) {
        return count(n);
    }
};