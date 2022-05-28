class Solution {
public:
    
//     // O(2*N) space and O(N) time complexity
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
        
//         // leftprod stores product of all numbers to left of i
//         // rightprod stores product of all number to right of i
//         vector<int> leftProd(n,1), rightProd(n,1);
//         vector<int> ans(n);
        
//         for(int i=1;i<n;i++){
//             leftProd[i] = nums[i-1]*leftProd[i-1];
//         }
//         for(int i=n-2;i>=0;i--){
//             rightProd[i] = nums[i+1]*rightProd[i+1];
//         }
//         for(int i=0;i<n;i++){
//             ans[i] = leftProd[i]*rightProd[i];
//         }
//         return ans;
//     }
    
    // O(1) space and O(N) time complexity
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int leftProd = 1, rightProd = 1;
        vector<int> ans(n,1);
        
        for(int i=0;i<n;i++){
            ans[i] = ans[i] * leftProd;
            leftProd = leftProd * nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i] * rightProd;
            rightProd = rightProd * nums[i];
        }
        return ans;
    }
};