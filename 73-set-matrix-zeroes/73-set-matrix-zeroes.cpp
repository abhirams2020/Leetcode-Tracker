class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows,cols;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(rows.count(i) || cols.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
//     void setZeroes(vector<vector<int>>& matrix) {
//         bool rowzero = false, colzero = false;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]==0){
//                     if(i==0)
//                         rowzero = true;
//                     if(j==0)
//                         colzero = true;
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//             }
//         }
        
//         for(int i=1;i<matrix.size();i++){
//             for(int j=1;j<matrix[0].size();j++){
//                 if(matrix[i][0]==0 || matrix[0][j]==0){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
        
//         if(rowzero == true){
//             for(int j=0;j<matrix[0].size();j++){
//                 matrix[0][j] = 0;
//             }
//         }
//         if(colzero == true){
//             for(int i=0;i<matrix.size();i++){
//                 matrix[i][0] = 0;
//             }
//         }
//     }
};