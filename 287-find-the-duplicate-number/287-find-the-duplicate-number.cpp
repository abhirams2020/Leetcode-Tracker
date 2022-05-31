class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])] < 0){
                return abs(nums[i]);
            }
            nums[abs(nums[i])] = -abs(nums[abs(nums[i])]);
        }
        return -1;
    }
};