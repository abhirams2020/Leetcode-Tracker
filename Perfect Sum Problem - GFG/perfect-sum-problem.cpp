// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	vector<vector<int>> dp;
	int mod = 1e9+7;
	
	int countSum(int arr[], int n, int sum){
	    if(n==1){
	        if(sum==0 && arr[0]==0){
	            return 2;
	        }
	        if(sum==0 || arr[0]==sum){
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[n][sum]!=-1){
	        return (dp[n][sum])%mod;
	    }
	    if(arr[n-1]<=sum){
	        return dp[n][sum] = (countSum(arr,n-1,sum-arr[n-1])+countSum(arr,n-1,sum))%mod;
	    }
	    return dp[n][sum] = countSum(arr,n-1,sum)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        dp.resize(n+1, vector<int>(sum+1, -1));
        return countSum(arr,n,sum);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends