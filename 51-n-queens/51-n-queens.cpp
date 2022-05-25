class Solution {
public:
    vector<vector<string>> res;
    
    bool isValid(vector<string>& board, int n, int row, int col){
        // UP
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        
        // SIDE
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        
        // LEFT DIAGONAL
        int i = row, j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        // RIGHT DIAGONAL
        i = row, j = col;
        while(i>=0 && j<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    
    void dfs(vector<string>& board, int n, int queens, int index){
        if(queens==n){
            res.push_back(board);
            return;
        }
        if(index==board.size()){
            return;
        }
        for(int i=index;i<n;i++){
            for(int j=0;j<n;j++){
                if(isValid(board,n,i,j)){
                    board[i][j] = 'Q';
                    dfs(board,n,queens+1,i+1);
                    board[i][j] = '.';
                }
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        dfs(board,n,0,0);
        return res;
    }
};