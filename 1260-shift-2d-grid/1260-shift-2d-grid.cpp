class Solution {
public:
   vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int m = grid.size();
       int n = grid[0].size();
       int r=0,c=0;
       vector<vector<int>> ans (m, vector<int> (n));
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               c = (j+k)%n;
               r = ((n*i+j+k)/n)%m;
               ans[r][c] = grid[i][j];
           }
       }
       return ans;
    }
};