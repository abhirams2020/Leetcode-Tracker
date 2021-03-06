class Solution {
public:
    // dp stores the min amount of coins to get amount at index
    // vector<vector<int>> dp;
    int dp[12][10000];
    
    int solve(vector<int>& coins, int amount, int index) {
        if(amount==0){
            return 0;
        }
        if(index==coins.size()){
            return INT_MAX-1;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        if(coins[index]<=amount){
            return dp[index][amount] = min(1+solve(coins,amount-coins[index],index), solve(coins,amount,index+1));
        }
        else{
            return dp[index][amount] = solve(coins,amount,index+1);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // dp.resize(coins.size(), vector<int>(amount+1,-1));
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,amount,0);
        if(ans == INT_MAX-1){
            return -1;
        }
        return ans;
    }
};