class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int ind = 0;
        for(;ind<nums.size();ind++){
            if(nums[ind]>0){
                break;
            }
        }
        if(ind==nums.size() || nums[ind]!=1) // no +ve number OR 1st positive not 1
            return 1;
        
        int ans = -1;
        while(ind < nums.size()-1){
            if(nums[ind]!=nums[ind+1] && nums[ind+1]!=nums[ind]+1){
                ans = nums[ind]+1;
                break;
            }
            ind++;
        }
        
        if(ans == -1){
            return nums[nums.size()-1]+1; //eg. arr = 0,1,2,3, then res is 4
        }
        
        return ans;
    }
};