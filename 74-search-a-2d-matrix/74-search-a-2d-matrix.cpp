class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start from last col in row 0.
        // at that pt, move left if target < matrix[row][col]
        // move down if target > matrix[row][col]. if equal then return true
        int row = 0, col = matrix[0].size()-1;
        while(row<matrix.size() && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                row++;
            }
            else if(matrix[row][col]>target){
                col--;
            }
        }
        return false;
    }
};