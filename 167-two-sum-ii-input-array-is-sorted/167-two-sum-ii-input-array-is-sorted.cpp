class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int l=0, r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r] == target){
                res = {l+1,r+1};
                break;
            }
            else if(nums[l]+nums[r] < target){
                l++;
            }
            else if(nums[l]+nums[r] > target){
                r--;
            }
        }
        return res;
    }
};