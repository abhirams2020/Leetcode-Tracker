class Solution {
public:
    vector<int> dpRow;
    vector<int> dpCol;
    vector<vector<int>> dpGrid;
    // int dpRow[9], dpCol[9], dpGrid[3][3];
    
    bool isValid(vector<vector<char>>& board, int row, int col){
        if(row==9){
            return true;
        }
        if(col==9){
            return isValid(board, row+1, 0);
        }
        if(board[row][col]!='.'){
            return isValid(board,row,col+1);
        }
        
        // CHECK DP COL
        if(dpCol[col]!=-1){
            if(dpCol[col]==0)
                return dpCol[col];
        }
        else {
            // CHECK COLUMN
            unordered_set<char> colSet;
            for(int i=0;i<9;i++){
                if(colSet.count(board[i][col])){
                    return dpCol[col] = 0;
                }
                if(board[i][col]!='.')
                    colSet.insert(board[i][col]);
            }
            dpCol[col] = 1;
        }
        
        // CHECK DP ROW
        if(dpRow[row]!=-1){
            if(dpRow[row]==0)
                return dpRow[row];
        }
        else {
            // CHECK ROW
            unordered_set<char> rowSet;
            for(int j=0;j<9;j++){
                if(rowSet.count(board[row][j])){
                    return dpRow[row] = 0;
                }
                if(board[row][j]!='.')
                    rowSet.insert(board[row][j]);
            }
            dpRow[row] = 1;    
        }
        
        // CHECK DP GRID

        int rowIndex = 3 * (row/3);
        int colIndex = 3 * (col/3);
        int gridRow = row/3;
        int gridCol = col/3;
        
        if(dpGrid[gridRow][gridCol]!=-1){
            if(dpGrid[gridRow][gridCol]==0){
                return false;
            }
        }
        else {
            // CHECK GRID
            unordered_set<char> gridSet;
            for(int i=rowIndex;i<rowIndex+3;i++){
                for(int j=colIndex;j<colIndex+3;j++){
                    if(gridSet.count(board[i][j])){
                        return dpGrid[gridRow][gridCol] = 0;
                    }
                    if(board[i][j]!='.')
                        gridSet.insert(board[i][j]);
                }
            }
            dpGrid[gridRow][gridCol] = 1;
        }
        
        // CURR POS IS VALID, SO CHECK NEXT POS 
        return isValid(board,row,col+1);
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        dpRow.resize(9,-1);
        dpCol.resize(9,-1);
        dpGrid.resize(3, vector<int>(3,-1));
        // memset(dpRow,-1,sizeof(dpRow));
        // memset(dpCol,-1,sizeof(dpCol));
        // memset(dpGrid,-1,sizeof(dpGrid));
        return isValid(board,0,0);
    }
};