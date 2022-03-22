class Solution {
public:
    // // O(N) space
    // vector<int> findDuplicates(vector<int>& nums) {
    //     set<int> s;
    //     vector<int> res;
    //     for(auto i:nums){
    //         if(s.count(i)){
    //             res.push_back(i);
    //         }
    //         s.insert(i);
    //     }
    //     return res;
    // }
    
    // O(1) space
    
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto i:nums){
            if(nums[abs(i)-1] < 0){
                res.push_back(abs(i));
            }
            nums[abs(i)-1] = -nums[abs(i)-1];
        }
        return res;
    }
};