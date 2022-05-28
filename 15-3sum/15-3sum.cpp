class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            int target = -nums[i];
            while(left<right){
                if(nums[left]+nums[right]==target){
                    vector<int> tempans = {nums[i],nums[left],nums[right]};
                    ans.push_back(tempans);
                    int curr_left = left, curr_right = right;
                    while(left<n && nums[curr_left]==nums[left]){
                        left++;
                    }
                    while(right>=i+1 && nums[curr_right]==nums[right]){
                        right--;
                    }
                }
                else if(nums[left]+nums[right]<target){
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return ans;
    }
};