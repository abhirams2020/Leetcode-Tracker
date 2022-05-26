class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int left=0, right=matrix[0].size()-1, top=0, bottom=matrix.size()-1;
        int dir = 0;
        
        while(left<=right and top<=bottom){
            // GO RIGHT
            if(dir==0){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            
            // GO DOWN
            else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            
            // GO LEFT
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // GO UP
            else if(dir==3){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            
            dir = (dir+1) % 4;
        }
        
        return res;
    }
};