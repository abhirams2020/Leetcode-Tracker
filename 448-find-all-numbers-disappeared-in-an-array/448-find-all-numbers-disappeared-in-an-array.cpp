class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // // O(n) time and O(n) space
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
        
        // O(1) space soln.
        // -ve index at position when element is found
        // eg. 3 1 2 2 -> -3 -1 -2 2. 4 is missing
        vector<int> res;
        for(auto i:nums){
            nums[(abs(i))-1] = -abs(nums[(abs(i))-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};