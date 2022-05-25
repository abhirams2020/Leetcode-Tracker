class Solution {
public:
    // dp[i] shows least cost to reach i
    vector<int> dp;
    
    int solve(vector<int> &cost, int index){
        // we can start from either 0 or 1
        if(index==0 || index==1){
            return 0;
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        return dp[index] = min(cost[index-1]+solve(cost,index-1), cost[index-2]+solve(cost,index-2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1,-1);
        // index = n, since we need to reach top of the stair at nth position
        return solve(cost, n);
    }
};