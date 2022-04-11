class Solution {
public:
    // consider 2d m*n array as 1d array
    // we can represent arr[i][j] as n*i + j
    // shift k times means n*i+j+k. %m if >m

    // eg [1][2] to [2][0] (shift by 1) in 4*3 grid
    // 0 -> (2+1)%3 %m if j>n-1
    // 2 -> (3*1+2+1)/3 = 1+(2+1)/3 = 6/3 = 2. %m if i>m-1
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int m = grid.size();
       int n = grid[0].size();
       int r=0,c=0;
       vector<vector<int>> ans (m, vector<int> (n));
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               c = (j+k)%n;
               r = (i+(j+k)/n)%m;
               ans[r][c] = grid[i][j];
           }
       }
       return ans;
    }
};