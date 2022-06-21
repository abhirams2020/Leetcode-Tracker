class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, minLen = INT_MAX;
        int l=0;
        for(int r=0; r<nums.size(); r++){
            sum += nums[r];
            while(l<nums.size() && sum>=target){
                minLen = min(minLen, r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        if(minLen==INT_MAX){
            return 0;
        }
        return minLen;
    }
};