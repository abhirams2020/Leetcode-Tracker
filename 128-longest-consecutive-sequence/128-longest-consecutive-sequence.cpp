class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    //     set<int> s;
    //     for(auto i:nums){
    //         s.insert(i);
    //     }
    //     int count = 1;
    //     int maxcount = 0;
    //     int prev = INT_MIN/2;
    //     for(auto curr:s){
    //         if(curr-prev==1){
    //             count++;
    //         }
    //         else {
    //             count=1;
    //         }
    //         prev = curr;
    //         maxcount = max(maxcount, count);
    //     }
    //     return maxcount;
    // }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int maxcount = 1;
        while(!s.empty()){
            int val = *s.begin();
            s.erase(val);
            int count = 1;
            
            // val, val+1, val+2 ...
            for(int i=val+1;s.count(i);i++){
                s.erase(i);
                count++;
            }
            
            // val-2, val-1, val ...
            for(int i=val-1;s.count(i);i--){
                s.erase(i);
                count++;
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};