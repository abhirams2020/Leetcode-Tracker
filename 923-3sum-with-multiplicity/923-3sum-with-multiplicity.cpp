class Solution {
public:
    
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;
        long mod = 1e9 + 7;
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            if(mp.count(target-arr[i])){
                ans = (ans + mp[target-arr[i]]) % mod;
            }
            for(int j=0;j<i;j++){
                mp[arr[i] + arr[j]]++;
            }
        }
        
        return ans;
    }
};