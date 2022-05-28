class Solution {
public:
    // CHECK IF ELEMENT ALREADY EXIST BEFORE ADDING TO SET
    
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums){
            if(s.count(i)!=0){
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};