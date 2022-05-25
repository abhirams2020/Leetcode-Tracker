class Solution {
public:
    int m=0, n=0;
    
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>> &board, string &word, int index, int i, int j){
        if(index == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        if(visited[i][j]==true || word[index]!=board[i][j]){
            return false;
        }
        visited[i][j] = true;
        bool ans =  dfs(board,word,index+1,i-1,j) ||
                    dfs(board,word,index+1,i+1,j) ||
                    dfs(board,word,index+1,i,j-1) ||
                    dfs(board,word,index+1,i,j+1);
        visited[i][j] = false;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        visited = vector<vector<bool>> (m, vector<bool>(n));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0] && dfs(board,word,0,i,j)){
                        return true;
                }
            }
        }
        
        return false;
    }
};