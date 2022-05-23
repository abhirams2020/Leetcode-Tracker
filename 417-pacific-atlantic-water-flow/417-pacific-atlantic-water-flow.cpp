class Solution {
public:
    vector<vector<int>> direction = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int i, int j){
        int m = heights.size(), n = heights[0].size();
        // if(i<0 || j<0 || i==m || j==n) {
        //     return;
        // }
        
        if(visited[i][j] == true)
            return;
        
        visited[i][j] = true;
        
        // do dfs
        if(i+1<m && heights[i+1][j]>=heights[i][j])
            dfs(heights,visited,i+1,j);
        if(i-1>=0 && heights[i-1][j]>=heights[i][j])
            dfs(heights,visited,i-1,j);
        if(j+1<n && heights[i][j+1]>=heights[i][j])
            dfs(heights,visited,i,j+1);
        if(j-1>=0 && heights[i][j-1]>=heights[i][j])
            dfs(heights,visited,i,j-1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool> (n,false));
        vector<vector<bool>> atlantic(m, vector<bool> (n,false));
        
        // for(int i=0;i<heights.size();i++){
        //     for(int j=0;j<heights[0].size();j++){
        //         if(i==0 || j==0){
        //             dfs(heights,pacific,i,j);
        //         }
        //         if(i==m-1 || j==n-1){
        //             dfs(heights,atlantic,i,j);
        //         }
        //     }
        // }
        
        // iterating through first COLUMN for pacific and last for atlantic
        for(int i=0;i<m;i++){
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,n-1);
        }
        
        // iterating through first ROW for pacific and last for atlantic
        for(int j=0;j<n;j++){
            dfs(heights,pacific,0,j);
            dfs(heights,atlantic,m-1,j);
        }
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j] == true && atlantic[i][j] == true){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};