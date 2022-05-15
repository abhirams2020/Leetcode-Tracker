class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int start = 1, end = 1;
        for(int i=0;i<n;i++){
            res[i] *= start;
            start *= nums[i];
        }
        
        for(int i=n-1;i>=0;i--){
            res[i] *= end;
            end *= nums[i];
        }
        
        return res;
    }
};