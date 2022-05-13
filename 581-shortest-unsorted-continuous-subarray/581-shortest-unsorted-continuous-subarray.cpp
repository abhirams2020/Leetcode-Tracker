class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start=0,end=n-1;
        vector<int> dup(nums.begin(), nums.end());
        
        sort(dup.begin(),dup.end());
        
        for(int i=0;i<n;i++){
            if(nums[i]!=dup[i]){
                break;
            }
            start++;
        }
        
        if(start == n){
            return 0;
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=dup[i]){
                break;
            }
            end--;
        }
        
        if(start!=end){
            return end - start + 1;
        }
        return 0;
        
    }
};