class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, count=0;
        ans = nums[0];
        for(auto i:nums){
            if(count == 0){
                ans = i;
            }
            if(ans == i){
                count+=1;
            }
            else {
                count-=1;
            }
        }
        return ans;
    }
};