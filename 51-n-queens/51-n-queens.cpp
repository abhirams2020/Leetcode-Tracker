class Solution {
public:
    
    vector<vector<string>> res;
    
    bool isValid(vector<string> &board, int row, int col){
        // //check row
        // for(int j=0;j<board[0].size();j++){
        //     if(board[row][j] == 'Q'){
        //         return false;
        //     }
        // }
        
        //check col
        for(int i=0;i<=row;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        
        // check left diagonal upwards(\)
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        // check right diagonal upwards(/)
        i=row,j=col;
        while(i>=0 && j<board[0].size()){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        
        return true;
    }
    
    bool solve(vector<string> &board, int row, int n){
        if(row==board.size() || n==0){
            res.push_back(board);
            return true;
        }
        for(int j=0;j<board.size();j++){
            if(isValid(board,row,j)){
                board[row][j] = 'Q';
                solve(board,row+1,n-1);
                board[row][j] = '.';
            }
        }
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(board,0,n);
        return res;
    }
};