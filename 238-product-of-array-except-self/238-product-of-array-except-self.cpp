class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n,1), rightProd(n,1);
        vector<int> ans(n);
        
        for(int i=1;i<n;i++){
            leftProd[i] = nums[i-1]*leftProd[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightProd[i] = nums[i+1]*rightProd[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i] = leftProd[i]*rightProd[i];
        }
        return ans;
    }
};