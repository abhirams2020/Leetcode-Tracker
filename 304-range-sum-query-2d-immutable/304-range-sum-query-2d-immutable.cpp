class NumMatrix {
public:
    
    void printVector(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<matrix[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    NumMatrix(vector<vector<int>>& matrix) {
        arr = matrix;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(i!=0){
                    arr[i][j] += arr[i-1][j];
                }
                if(j!=0){
                    arr[i][j] += arr[i][j-1];
                }
                if(i!=0 && j!=0){
                    arr[i][j] -= arr[i-1][j-1];
                }
            }
        }
        printVector(arr);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!row1 && !col1){
            return arr[row2][col2];
        }
        if(!row1){
            return arr[row2][col2] - arr[row2][col1-1];
        }
        if(!col1){
            return  arr[row2][col2] - arr[row1-1][col2];
        }
        
        return arr[row2][col2] - arr[row1-1][col2] - arr[row2][col1-1] + arr[row1-1][col1-1];
    }
private:
    vector<vector<int>> arr;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */