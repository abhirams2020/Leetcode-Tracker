class Solution {
public:
    // USING XOR
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(auto i:nums){
            ans = ans^i;
        }
        return ans;
    }
    
    // // USING BINARY SEARCH
    // int singleNonDuplicate(vector<int>& nums) {
    //     if(nums.size()==1){
    //         return nums[0];
    //     }
    //     int left=0, right=nums.size()-1;
    //     while(left<=right){
    //         int mid = (left+right)/2;
    //         cout<<mid<<endl;
    //         if(mid>0 && nums[mid]==nums[mid-1]){
    //             if((left-mid+1)%2==0){
    //                 left = mid+1;
    //             }
    //             else {
    //                 right = mid;
    //             }
    //         }
    //         else if(mid<nums.size()-1 && nums[mid]==nums[mid+1]){
    //             if((mid-right+1)%2==0){
    //                 right = mid-1;
    //             }
    //             else {
    //                 left = mid;
    //             }                
    //         }
    //         else {
    //             return nums[mid];
    //         }
    //     }
    //     return 0;
    // }
};