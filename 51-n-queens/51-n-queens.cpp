class Solution {
public:
    vector<vector<string>> res;
    
    bool isValid(vector<string>& board, int n, int row, int col){
        // CHECK UP
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        
        // CHECK LEFT DIAGONAL
        int i = row, j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        // CHECK RIGHT DIAGONAL
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
    
    void dfs(vector<string>& board, int n, int queens, int row){
        if(row==board.size() || queens==n){
            res.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isValid(board,n,row,j)){
                board[row][j] = 'Q';
                dfs(board,n,queens+1,row+1);
                board[row][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        dfs(board,n,0,0);
        return res;
    }
};