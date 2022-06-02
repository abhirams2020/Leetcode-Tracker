class Solution {
public:
    int maxProduct(vector<int>& nums) {
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