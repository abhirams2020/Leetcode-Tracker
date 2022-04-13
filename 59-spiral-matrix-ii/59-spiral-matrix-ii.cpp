class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int L=0, R=n-1, U=0, D=n-1;
        int dir = 0;
        for(int i=1;i<=n*n;){
            if(dir == 0){
                for(int j=L;j<=R;j++){
                    res[U][j] = i;
                    i++;
                }
                U++;
            }
            else if(dir == 1){
                for(int j=U;j<=D;j++){
                    res[j][R] = i;
                    i++;
                }
                R--;
            }
            else if(dir == 2){
                for(int j=R;j>=L;j--){
                    res[D][j] = i;
                    i++;
                }
                D--;
            }
            else if(dir == 3){
                for(int j=D;j>=U;j--){
                    res[j][L] = i;
                    i++;
                }
                L++;
            }
            dir = (dir+1)%4;
        }
        return res;
    }
};