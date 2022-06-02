class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // if nums[i] is negative and minSoFar is negative, it can give largest product
        // so store currMax and currMin values.
        int currMin=nums[0], currMax=nums[0], maxProd=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevMin = currMin, prevMax = currMax;
            currMin = min(nums[i], min(prevMin*nums[i], prevMax*nums[i]));
            currMax = max(nums[i], max(prevMin*nums[i], prevMax*nums[i]));
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};