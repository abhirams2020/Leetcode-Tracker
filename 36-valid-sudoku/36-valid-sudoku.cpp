class Solution {
public:
    int dpRow[9];
    int dpCol[9];
    int dpGrid[3][3];
    bool check(vector<vector<char>>& board, int row, int col){

        if(row==board.size()-1 && col==board.size()-1){
            return true;
        }
        if(col==board.size()){
            return check(board, row+1, 0);
        }
        if(board[row][col]=='.'){
            return check(board, row, col+1);
        }
        unordered_set<char> s;
        if(dpCol[col]!=-1){
            if(dpCol[col]==0){
                return false;
            }
        }
        else {
            for(int i=0;i<9;i++){
                if(s.count(board[i][col])){
                    dpCol[col]=0;
                    return false;
                }
                if(board[i][col]!='.')
                    s.insert(board[i][col]);
            }
            dpCol[col]=1;
            s.clear();            
        }
        
        if(dpRow[row]!=-1){
            if(dpRow[row]==0){
                return false;
            }
        }
        else {
            for(int j=0;j<9;j++){
                if(s.count(board[row][j])){
                    dpRow[row] = 0;
                    return false;
                }
                if(board[row][j]!='.')
                    s.insert(board[row][j]);
            }
            dpRow[row] = 1;
            s.clear();            
        }

        int dpRow = row/3, dpCol = col/3;
        if(dpGrid[dpRow][dpCol]!=-1){
            if(dpGrid[dpRow][dpCol]==0){
                return false;
            }
        }
        else{        
            int gridRow = 3*(row/3);
            int gridCol = 3*(col/3);
            for(int i=gridRow; i<gridRow+3;i++){
                for(int j=gridCol; j<gridCol+3; j++){
                    if(s.count(board[i][j])){
                        dpGrid[dpRow][dpCol] = 0;
                        return false;
                    }
                    if(board[i][j]!='.')
                        s.insert(board[i][j]);
                }
            }
            dpGrid[dpRow][dpCol] = 1;
        }
        return check(board, row, col+1);
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(dpCol,-1,sizeof(dpCol));
        memset(dpRow,-1,sizeof(dpRow));
        memset(dpGrid,-1,sizeof(dpGrid));
        return check(board,0,0);
    }
};