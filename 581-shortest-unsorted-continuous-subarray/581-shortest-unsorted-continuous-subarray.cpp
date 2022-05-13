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
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int small = INT_MAX, large = INT_MIN;
        int start=-1,end=n-1;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                large = max(nums[i], large);
            }
        }
        
        for(int i=n-1;i>=1;i--){
            if(nums[i]<nums[i-1]){
                small = min(nums[i], small);
            }
        }
        
        for(int i=n-1;i>=1;i--){
            if(nums[i]<large){
                end = i;
                break;
            }
        }
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>small){
                start = i;
                break;
            }
        }
        
        if(start!=-1){
            return end - start + 1;
        }
        return 0;
        
    }
};