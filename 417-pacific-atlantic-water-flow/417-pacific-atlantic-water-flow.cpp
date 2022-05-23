class Solution {
public:
    vector<vector<int>> direction = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int i, int j){
        int m = heights.size(), n = heights[0].size();
        if(i<0 || j<0 || i==m || j==n) {
            return;
        }
        
        if(visited[i][j] == true)
            return;
        
        visited[i][j] = true;
        
        // do dfs
        for(auto dir:direction){
            int next_i = i+dir[0];
            int next_j = j+dir[1];
            if(next_i>=0 && next_i<m && next_j>=0 && next_j<n && heights[next_i][next_j] >= heights[i][j])
                dfs(heights, visited, next_i, next_j);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool> (n));
        vector<vector<bool>> atlantic(m, vector<bool> (n));
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(i==0 || j==0){
                    dfs(heights,pacific,i,j);
                }
                if(i==m-1 || j==n-1){
                    dfs(heights,atlantic,i,j);
                }
            }
        }
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j] == 1 and atlantic[i][j] == 1){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};