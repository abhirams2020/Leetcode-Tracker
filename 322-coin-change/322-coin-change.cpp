class Solution {
public:

    int dp[12][10000];
    
    int solve(vector<int> &coins, int amount, int ind){
        if(amount == 0){
            return 0;
        }
        
        if(ind==coins.size()){
            return INT_MAX-1;
        }
        
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        
        if(coins[ind]<=amount){
            return dp[ind][amount] = min(1+solve(coins,amount-coins[ind],ind), solve(coins,amount,ind+1));
        }
        else {
            return dp[ind][amount] = solve(coins,amount,ind+1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,amount,0);
        return (ans == INT_MAX-1)?-1:ans;
    }
};