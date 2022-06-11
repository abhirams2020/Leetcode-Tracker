class Solution {
public:
    // Goal is to find a window of longest length which has sum equal to s - x, 
    // where s is sum of all the elements of the array.
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, ans = INT_MAX;
        for(auto i:nums){
            sum += i;
        }
        // find max size subarray with sum = sum - x;
        int target = sum - x;
        
        // if all elements reqd to sum to x, return size of all elements
        // if we dont do this, the code will return -1 due to 0 window size
        if(target==0){
            return nums.size();
        }
        if(target < 0){
            return -1;
        }
        int currSum = 0;
        int left = 0;
        int maxLen = 0;
        
        // add elements of right ptr to currSum. if currSum>target, remove left ptr till currSum<=target
        for(int right=0; right<nums.size(); right++){
            currSum = currSum + nums[right];
            while(left<nums.size() && currSum > target){
                currSum -= nums[left];
                left++;
            }
            if(currSum == target){
                maxLen = max(maxLen, right-left+1);
            }
        }
        if(maxLen == 0){
            return -1;
        }
        return nums.size()-maxLen;
    }
};