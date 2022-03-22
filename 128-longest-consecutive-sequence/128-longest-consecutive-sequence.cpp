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
        for(auto curr:s){
            if(curr-prev==1){
                count++;
            }
            else {
                count=1;
            }
            prev = curr;
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};