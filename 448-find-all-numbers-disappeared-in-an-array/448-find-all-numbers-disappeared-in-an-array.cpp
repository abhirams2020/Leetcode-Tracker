class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // vector<bool> seen(nums.size()+1);
        // vector<int> res;
        // for(auto i:nums){
        //     seen[i] = true;
        // }
        // for(int i=1;i<=nums.size();i++){
        //     if(!seen[i]){
        //         res.push_back(i);
        //     }
        // }
        // return res;
        vector<int> res;
        for(auto i:nums){
            nums[(abs(i))-1] = -abs(nums[(abs(i))-1]);
        }
        for(auto i:nums){
            cout<<i<<" ";
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};