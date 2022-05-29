class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<=right){
            while(left<nums.size()-1 && nums[left]==nums[left+1]){
                left+=2;
            }
            while(right>=1 && nums[right]==nums[right-1]){
                right-=2;
            }
            return nums[left];
        }
        return 0;
    }
};