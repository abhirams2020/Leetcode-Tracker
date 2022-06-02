class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        
        // find first occurrance
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                start = mid;
                r = mid-1; // to check more on left
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else {
                r = mid-1;   
            }
        }
        
        // find last occurrance
        l=0, r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                end = mid;
                l = mid+1; // to check more on right
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else {
                r = mid-1;   
            }
        }
        
        return {start,end};
    }
};