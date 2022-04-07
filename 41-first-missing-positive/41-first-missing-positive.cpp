class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int min = INT_MAX;
        for(auto i:nums){
            if(i>0){
                min = i;
                break;
            }
        }
        if(min!=1)
            return 1;
        
        int ind = 0;
        int ans = -1;
        while(ind < nums.size()-1){
            if(nums[ind]>=0 && nums[ind+1]!=nums[ind]+1 && nums[ind]!=nums[ind+1]){
                ans = nums[ind]+1;
                break;
            }
            ind++;
        }
        if(ans == -1){
            ans = nums[nums.size()-1]+1;
        }
        return ans;
    }
};