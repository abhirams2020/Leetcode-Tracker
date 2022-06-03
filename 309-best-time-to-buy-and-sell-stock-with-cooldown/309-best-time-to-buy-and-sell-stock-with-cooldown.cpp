class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int> &prices, int i, int minIndex){
        if(i>=prices.size()){
            return 0;
        }
        if(minIndex==-1 || prices[i] < prices[minIndex]){
            minIndex = i;
        }
        if(dp[i][minIndex]!=-1){
            return dp[i][minIndex];
        }
        int currProfit = prices[i]-prices[minIndex];
        // if profit is there, include and reset minimum or not include it and return the max of both.
        if(currProfit > 0){
            return dp[i][minIndex] = max(currProfit + solve(prices,i+2,-1), solve(prices,i+1,minIndex));
        }
        // if no profit at curr index, proceed to next
        return dp[i][minIndex] = solve(prices,i+1,minIndex);
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<int>(n+1,-1));
        int minIndex = -1;
        return solve(prices, 0, -1);
    }
};