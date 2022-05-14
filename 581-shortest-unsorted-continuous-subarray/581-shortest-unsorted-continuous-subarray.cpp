class Solution {
public:
    
    // sort the array and compare each element O(N log N)
//     int findUnsortedSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int start=0,end=n-1;
//         vector<int> dup(nums.begin(), nums.end());
        
//         sort(dup.begin(),dup.end());
        
//         for(int i=0;i<n;i++){
//             if(nums[i]!=dup[i]){
//                 break;
//             }
//             start++;
//         }
        
//         if(start == n){
//             return 0;
//         }
        
//         for(int i=n-1;i>=0;i--){
//             if(nums[i]!=dup[i]){
//                 break;
//             }
//             end--;
//         }
        
//         if(start!=end){
//             return end - start + 1;
//         }
//         return 0;
//     }
    
    // O(N) time
    
    // find largest and smallest element that are not in order
    // for largest, go from back and find the position to fit it
    // for smallest, go from front and find the position to fit it
    // if there exist a subarray that need to be sorted, the start position will be changed
    // so we check if start is -1. if not we return the length of subarray. else 0
    
    bool isOutOfOrder(vector<int>& nums, int i){
        if(nums.size() <= 1){
            return false;
        }
        if(i==0){
            return nums[i]>nums[i+1];
        }
        if(i==nums.size()-1){
            return nums[i]<nums[i-1];
        }
        return nums[i]>nums[i+1] || nums[i]<nums[i-1];
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int small = INT_MAX, large = INT_MIN;
        int start=0, end=n-1;
        
        for(int i=0;i<n;i++){
            if(isOutOfOrder(nums,i)){
                small = min(nums[i], small);
                large = max(nums[i], large);
            }
        }
    
        while(start<n-1 && small >= nums[start]){
            start++;
        }
        
        while(end>0 && large <= nums[end]){
            end--;
        }
        
        if(small == INT_MAX){
            return 0;
        }
        
        return end - start + 1;
    
    }
};