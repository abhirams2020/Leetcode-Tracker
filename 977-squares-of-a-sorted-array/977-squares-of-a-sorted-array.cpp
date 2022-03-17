class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        int l=0,r=size-1;
        while(l<=r){
            if(abs(nums[l]) > abs(nums[r])){
                res.push_back(nums[l] * nums[l]);
                l++;
            }
            else {
                res.push_back(nums[r] * nums[r]);
                r--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};