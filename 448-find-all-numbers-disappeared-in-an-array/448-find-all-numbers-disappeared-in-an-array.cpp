class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> seen(nums.size()+1);
        vector<int> res;
        for(auto i:nums){
            seen[i] = true;
        }
        for(int i=1;i<=nums.size();i++){
            if(!seen[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};