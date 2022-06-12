class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i==m-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=0;k<n;k++){
            ans = min(ans, grid[i][j] + moveCost[grid[i][j]][k] + solve(grid,moveCost,i+1,k));
        }
        return dp[i][j] = ans;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size(), n=grid[0].size();
        dp.resize(m+1,vector<int> (n+1,-1));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, solve(grid,moveCost,0,i));
        }
        return ans;
    }
};