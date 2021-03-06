class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            // curr_level will have prev_level+1 elements between 1 to 1
            // from index=1, no of elements bw 1 to 1 in i'th row = i-1
            for(int j=0;j<i-1;j++){
                temp.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};