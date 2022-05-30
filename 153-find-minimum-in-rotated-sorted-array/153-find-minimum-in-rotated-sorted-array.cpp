class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        // if array is sorted, return nums[left]
        while(left<right && nums[left]>nums[right]){
            int mid = left + (right-left)/2;
            // smallest element will be in part with pivot element
            
            // if pivot is in left side
            if(nums[left]>nums[mid]){
                right = mid;
            }
            
            // if pivot is in right side
            else if(nums[mid]>nums[right]){
                left = mid+1;
            }
        }
        return nums[left];
    }
};