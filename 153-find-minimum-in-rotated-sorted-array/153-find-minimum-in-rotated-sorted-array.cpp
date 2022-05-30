class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[left]<nums[right]){
                right = left;
            }
            else if(nums[left]>nums[mid]){
                right = mid;
            }
            else if(nums[mid]>nums[right]){
                left = mid+1;
            }
        }
        return nums[left];
    }
};