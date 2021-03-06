// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string> res;
    
    void solve(vector<vector<int>> &m, int row, int col, int size, string op) {
        if(row<0 || row>size-1 || col<0 || col>size-1){
            return;
        }
        if(m[row][col]==0){
            return;
        }
        if(row == size-1 and col == size-1){
            res.push_back(op);
            return;
        }
        m[row][col] = 0;
        solve(m,row+1,col,size,op+'D');
        solve(m,row-1,col,size,op+'U');
        solve(m,row,col+1,size,op+'R');
        solve(m,row,col-1,size,op+'L');
        m[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string op = "";
        solve(m,0,0,n,op);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends