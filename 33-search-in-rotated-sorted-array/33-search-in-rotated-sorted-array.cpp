class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            // if left side of mid is sorted
            else if(nums[left]<=nums[mid]){
                // if target is in left side of mid, search range left to mid
                if(target >= nums[left] && target <= nums[mid]){
                    right = mid;
                }
                // if target not in left side, search mid+1 to right range
                else {
                    left = mid + 1;
                }
            }
            // if right side of mid is sorted
            else if(nums[mid]<=nums[right]){
                // if target is in right side of mid, search range right to mid
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid;
                }
                // if target not in right side, search left to mid-1 range
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};