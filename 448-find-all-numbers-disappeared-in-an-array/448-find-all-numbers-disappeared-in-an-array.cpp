class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;
        for(auto i:nums){
            s.insert(i);
        }
        for(int i=1;i<=nums.size();i++){
            if(s.count(i)==0){
                res.push_back(i);
            }
        }
        return res;
    }
};