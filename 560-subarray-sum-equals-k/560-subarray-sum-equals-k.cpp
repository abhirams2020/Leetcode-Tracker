class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0, prefixSum=0;
        // mp[prefixSum] gives no of time that sum occurred before i
        unordered_map<int,int> mp;
        // initialise mp[0]=1 to count elements with same value as k
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            if(mp.count(prefixSum-k)){
                // if subarray with sum=k, found add number of such  subarrays to count
                count += mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};