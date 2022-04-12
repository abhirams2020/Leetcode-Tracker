class Solution {
public:
    
    int check(vector<vector<int>>& board, int i, int j){
        if(i<0 || j<0 || i==board.size() || j==board[0].size()){
            return 0;
        }
        return board[i][j];
    }
    
    int countNeighbours(vector<vector<int>>& board, int i, int j){
        return  check(board,i-1,j)      +   check(board,i+1,j)+
                check(board,i,j-1)      +   check(board,i,j+1)+
                check(board,i+1,j+1)    +   check(board,i-1,j-1)+
                check(board,i-1,j+1)    +   check(board,i+1,j-1);
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> curr = board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count = countNeighbours(curr,i,j);
                if(board[i][j] == 1 && (count < 2 || count > 3)){
                    board[i][j] = 0;
                }
                else if(board[i][j] == 0 && count == 3){
                    board[i][j] = 1;    
                }
            }
        }
    }
};