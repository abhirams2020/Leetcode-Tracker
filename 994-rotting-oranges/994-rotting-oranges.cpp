class Solution {
public:
    int m = 0, n = 0;
    
    int bfs(vector<vector<int>>& grid, vector<pair<int,int>> &rotten){
        queue<pair<int,int>> q;
        for(auto i:rotten){
            q.push({i.first,i.second});
        }
        int minTime = 0;
        int time = 0;
        while(!q.empty()){
            int qSize = q.size();
            minTime = time;
            
            for(int i=0;i<qSize;i++){
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                
                if(curr_i+1<m && grid[curr_i+1][curr_j]==1){
                    grid[curr_i+1][curr_j] = 2;                    
                    q.push({curr_i+1,curr_j});
                }

                if(curr_i-1>=0 && grid[curr_i-1][curr_j]==1){
                    grid[curr_i-1][curr_j] = 2;
                    q.push({curr_i-1,curr_j});
                }

                if(curr_j+1<n && grid[curr_i][curr_j+1]==1){
                    grid[curr_i][curr_j+1] = 2;
                    q.push({curr_i,curr_j+1});                    
                }

                if(curr_j-1>=0 && grid[curr_i][curr_j-1]==1){
                    grid[curr_i][curr_j-1] = 2;
                    q.push({curr_i,curr_j-1});                    
                }
                
                q.pop();
            }
            time++;
        }
        return minTime;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<pair<int,int>> rotten;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    rotten.push_back({i,j});
                }
            }
        }
        
        int minTime = bfs(grid,rotten);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minTime;
    }
};