class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int currMin=nums[0], currMax=nums[0], maxProd=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevMax = currMax, prevMin = currMin;
            currMax = max(max(prevMin*nums[i],currMax*nums[i]), nums[i]);
            currMin = min(min(prevMax*nums[i],currMin*nums[i]), nums[i]);
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};