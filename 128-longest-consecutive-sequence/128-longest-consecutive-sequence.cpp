class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int count = 1;
        int maxcount = 0;
        int prev = INT_MIN/2;
        for(auto i:s){
            if(i-prev==1){
                count++;
            }
            else {
                count=1;
            }
            prev = i;
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};