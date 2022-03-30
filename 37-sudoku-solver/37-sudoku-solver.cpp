class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col, char num){
        // check row
        for(int j=0;j<board[0].size();j++){
            if(board[row][j]==num){
                return false;
            }
        }
        
        // check col
        for(int i=0;i<board.size();i++){
            if(board[i][col]==num){
                return false;
            }
        }
        
        // check grid
        int grid_row = 3*(row/3);
        int grid_col = 3*(col/3);
        for(int i=grid_row;i<grid_row+3;i++){
            for(int j=grid_col;j<grid_col+3;j++){
                if(board[i][j]==num){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int row, int col){
        if(row==board.size()){
            return true;
        }
        if(col==board[0].size()){
            return solve(board,row+1,0);
        }
        if(board[row][col]!='.'){
            return solve(board,row,col+1);
        }
        for(char num='1';num<='9';num++){
            if(isValid(board,row,col,num)){
                board[row][col] = num;
                if(solve(board,row,col+1)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};