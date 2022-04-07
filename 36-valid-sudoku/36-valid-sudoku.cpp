class Solution {
public:
    int dp[3][3];
    bool check(vector<vector<char>>& board, int row, int col){

        if(row==board.size()-1 && col==board.size()-1){
            return true;
        }
        if(col==board.size()){
            return check(board, row+1, 0);
        }
        unordered_set<char> s;
        for(int i=0;i<9;i++){
            if(s.count(board[i][col])){
                cout<<i<<" "<<col;
                return false;
            }
            if(board[i][col]!='.')
                s.insert(board[i][col]);
        }
        s.clear();
        for(int j=0;j<9;j++){
            if(s.count(board[row][j])){
                cout<<row<<" "<<j;
                return false;
            }
            if(board[row][j]!='.')
                s.insert(board[row][j]);
        }
        s.clear();
        int gridRow = 3*(row/3);
        int gridCol = 3*(col/3);
        int dpRow = row/3, dpCol = col/3;
        if(dp[dpRow][dpCol]!=-1){
            if(dp[dpRow][dpCol]==0){
                return false;
            }
        }
        else{
            for(int i=gridRow; i<gridRow+3;i++){
                for(int j=gridCol; j<gridCol+3; j++){
                    if(s.count(board[i][j])){
                        cout<<i<<" "<<j;
                        dp[dpRow][dpCol] = 0;
                        return false;
                    }
                    if(board[i][j]!='.')
                        s.insert(board[i][j]);
                }
            }
            dp[dpRow][dpCol] = 1;
        }

        
        return check(board, row, col+1);
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(dp,-1,sizeof(dp));
        return check(board,0,0);
    }
};