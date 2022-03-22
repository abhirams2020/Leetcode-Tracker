class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> res;
        for(auto i:nums){
            if(s.count(i)){
                res.push_back(i);
            }
            s.insert(i);
        }
        return res;
    }
};