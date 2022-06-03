// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<int>> dp;
    
    bool solve(vector<int> &arr, int index, int sum){
        if(sum==0){
            return true;
        }    
        if(index==arr.size()){
            return false;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        if(arr[index]<=sum){
            return dp[index][sum] = (solve(arr,index+1,sum-arr[index]) || solve(arr,index+1,sum));
        }
        return dp[index][sum] = solve(arr,index+1,sum);
    }
    
    bool isSubsetSum(vector<int> &arr, int sum){
        // code here
        dp.resize(arr.size()+1, vector<int>(sum+1,-1));
        return solve(arr,0,sum);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends