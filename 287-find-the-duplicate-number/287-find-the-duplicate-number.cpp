class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res;
        for(auto i:nums){
            if(nums[abs(i)-1] < 0){
                res = abs(i);
            }
            nums[abs(i)-1] = -nums[abs(i)-1];
        }
        return res;
    }
};