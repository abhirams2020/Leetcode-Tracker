class Solution {
public:
    // CHECK IF ELEMENT ALREADY EXIST BEFORE ADDING TO SET
    
    // bool containsDuplicate(vector<int>& nums) {
    //     unordered_set<int> s;
    //     for(auto i:nums){
    //         if(s.count(i)!=0){
    //             return true;
    //         }
    //         s.insert(i);
    //     }
    //     return false;
    // }
    
    // SORT ARRAY AND CHECK IF ADJACENT ELEMENTS ARE SAME
    
    // bool containsDuplicate(vector<int> &nums){
    //     sort(nums.begin(),nums.end());
    //     for(int i=1;i<nums.size();i++){
    //         if(nums[i-1]==nums[i]){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};