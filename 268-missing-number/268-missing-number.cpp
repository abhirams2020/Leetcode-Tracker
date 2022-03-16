class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        for(auto i:nums){
            res = res^i;
        }
        for(int i=0;i<=nums.size();i++){
            res = res^i;
        }
        return res;
    }
};