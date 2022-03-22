class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int start = 1, end = 1;
        for(int i=0;i<nums.size();i++){
            ans.push_back(start);
            start *= nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            ans[i] *= end;
            end *= nums[i];
        }
        return ans;
    }
};