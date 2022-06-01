class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int res=0;
        // for(auto i:nums){
        //     res = res^i;
        // }
        // for(int i=0;i<=nums.size();i++){
        //     res = res^i;
        // }
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        int n=nums.size();
        return (n*(n+1)/2) - sum;
    }
};