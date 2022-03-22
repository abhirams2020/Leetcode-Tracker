class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        vector<int> res;
        int dir = 0;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int j=left;j<=right;j++){
                    res.push_back(matrix[top][j]);
                }
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir==2){
                for(int j=right;j>=left;j--){
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            else if(dir==3){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;                
            }
            dir = (dir+1)%4;
        }
        return res;
    }
};