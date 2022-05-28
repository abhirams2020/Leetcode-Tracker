class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        // nums[i] should be less than or equal to 0 to get a valid result
        // if nums[i] is positive, numbers to its right is also positive and cannot give 0 sum
        for(int i=0;i<n-1 && nums[i]<=0;i++){
            // i will proceed only at non duplicate positions
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

                    // * removing duplicate trick *
                    // move left ptr to right till it reaches a larger value
                    // move right ptr to left till it reaches a smaller value
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