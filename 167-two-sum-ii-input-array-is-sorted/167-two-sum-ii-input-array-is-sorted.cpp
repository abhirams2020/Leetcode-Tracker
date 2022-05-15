class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int l=0, r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r] == target){
                res.push_back(l+1);
                res.push_back(r+1);
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