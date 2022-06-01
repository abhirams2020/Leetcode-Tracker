class Solution {
public:
    // // sum from 0 to n is n*(n+1)/2. subtract sum of nums from this.
    // int missingNumber(vector<int>& nums) {
    //     int sum = 0;
    //     for(auto i:nums){
    //         sum += i;
    //     }
    //     int n=nums.size();
    //     return (n*(n+1)/2) - sum;
    // }
    
    // using xor on original list and 0 to n list.
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