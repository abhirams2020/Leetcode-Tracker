class Solution {
public:
    
//     // this method, copy original matrix and use copied matrix for counting neighbour
//     // O(mn) space
//     int check(vector<vector<int>>& board, int i, int j){
//         if(i<0 || j<0 || i==board.size() || j==board[0].size()){
//             return 0;
//         }
//         return board[i][j];
//     }
    
//     int countNeighbours(vector<vector<int>>& board, int i, int j){
//         return  check(board,i-1,j)      +   check(board,i+1,j)+
//                 check(board,i,j-1)      +   check(board,i,j+1)+
//                 check(board,i+1,j+1)    +   check(board,i-1,j-1)+
//                 check(board,i-1,j+1)    +   check(board,i+1,j-1);
//     }
    
//     void gameOfLife(vector<vector<int>>& board) {
//         vector<vector<int>> curr = board;
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 int count = countNeighbours(curr,i,j);
//                 if(board[i][j] == 1 && (count < 2 || count > 3)){
//                     board[i][j] = 0;
//                 }
//                 else if(board[i][j] == 0 && count == 3){
//                     board[i][j] = 1;    
//                 }
//             }
//         }
//     }
    
    // This method, we dont modify old board
    // when we change 0 to 1, instead we change 0 to 3
    // when we change 1 to 0, instead we change 1 to 2
    // 2 means new 0, 3 means new 1
    // after traverse every cell, change 2 to 0 and 3 to 1.
    
    // O(1) space complexity
    int check(vector<vector<int>>& board, int i, int j){
        if(i<0 || j<0 || i==board.size() || j==board[0].size()){
            return 0;
        }
        if(board[i][j] == 0 || board[i][j] == 3){
            return 0;
        }
        if(board[i][j] == 1 || board[i][j] == 2){
            return 1;
        }
        return 0;
    }
    
    int countNeighbours(vector<vector<int>>& board, int i, int j){
        return  check(board,i-1,j)      +   check(board,i+1,j)+
                check(board,i,j-1)      +   check(board,i,j+1)+
                check(board,i+1,j+1)    +   check(board,i-1,j-1)+
                check(board,i-1,j+1)    +   check(board,i+1,j-1);
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count = countNeighbours(board,i,j);
                if(board[i][j] == 1 && (count < 2 || count > 3)){
                    board[i][j] = 2;
                }
                else if(board[i][j] == 0 && count == 3){
                    board[i][j] = 3;    
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j] = board[i][j] % 2;
            }
        }
    }
};