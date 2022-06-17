class Solution {
public:
    int dp[301][5001];
    
    int knapsack(vector<int> &coins, int target, int index){
        if(target==0){
            return 1;
        }
        if(index==coins.size()){
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        if(coins[index]<=target){
            // since inf no of coins, if current is valid include it and remain at current index
            // or not include and move to next index
            return dp[index][target] = knapsack(coins,target-coins[index],index) + knapsack(coins,target,index+1);
        }
        return dp[index][target] = knapsack(coins,target,index+1);
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return knapsack(coins,amount,0);
    }
};