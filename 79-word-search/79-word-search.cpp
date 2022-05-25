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
        if(word[index]!=board[i][j]){
            return false;
        }
        
        // change visited position to # to avoid repeating
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool ans =  dfs(board,word,index+1,i-1,j) ||
                    dfs(board,word,index+1,i+1,j) ||
                    dfs(board,word,index+1,i,j-1) ||
                    dfs(board,word,index+1,i,j+1);
        
        // change back the visited to original value
        board[i][j] = temp;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
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