class Solution {
public:
    // // if arr[i][j] is 0, rows with index=i and cols with index=j should be 0
    // // so add i to rows set and j to cols set
    // // if rows or cols contains the curr index, make it 0
    // void setZeroes(vector<vector<int>>& matrix) {
    //     unordered_set<int> rows,cols;
    //     for(int i=0;i<matrix.size();i++){
    //         for(int j=0;j<matrix[0].size();j++){
    //             if(matrix[i][j]==0){
    //                 rows.insert(i);
    //                 cols.insert(j);
    //             }
    //         }
    //     }
    //     for(int i=0;i<matrix.size();i++){
    //         for(int j=0;j<matrix[0].size();j++){
    //             if(rows.count(i) || cols.count(j)){
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }
    
    // Instead of using rows and cols set to store 0 index, use 1st row and 1st col of the matrix
    // If arr[i][j] is 0, make arr[i][0] and arr[0][j] = 0. But there is special condition here.
    // eg. [[1,1][0,1]] should be [[0,1][0,0]]. but if we check from i=0, we get [[0,0][0,0]]
    // First row/col should change to all zero only if it contained a zero initially.
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowzero = false, colzero = false;
        // check first row and col if it already contain 0
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                colzero = true;
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                rowzero = true;
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // for arr[i][j], if its row or col starting has 0, make it 0
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(rowzero == true){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j] = 0;
            }
        }
        if(colzero == true){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
    }
};