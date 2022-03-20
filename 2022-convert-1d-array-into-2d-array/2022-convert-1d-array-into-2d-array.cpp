class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> mat;
        if(m*n != original.size())
            return mat;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(original[i*n + j]);
            }
            mat.push_back(temp);
        }
        return mat;
    }
};