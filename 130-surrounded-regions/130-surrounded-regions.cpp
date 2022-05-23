class Solution {
private:
    int m = 0, n = 0;
    vector<vector<bool>> visited;
public:
    
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        
        if(board[i][j]=='X' || visited[i][j] == true)
            return;
        
        visited[i][j] = true;
        
        // DO DFS
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        visited = vector<vector<bool>> (m, vector<bool> (n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    dfs(board,i,j);
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
};