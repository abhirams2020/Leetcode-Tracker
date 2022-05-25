class Solution {
public:
//     vector<vector<int>> res;
    
//     void solve(vector<int> &nums, vector<int> op, int target, int index){
//         if(target == 0){
//             res.push_back(op);
//             return;
//         }
//         if(index==nums.size() || nums[index]>target){
//             return;
//         }
//         for(int i=index;i<nums.size();i++){
//             if(nums[i]<=target && (i==index || nums[i]!=nums[i-1])){
//                 op.push_back(nums[i]);
//                 solve(nums,op,target-nums[i],i+1);
//                 op.pop_back();
//             }
//         }
//     }
    
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<int> op;
//         solve(candidates, op, target, 0);
//         return res;
//     }
    
    void helper(int index, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int> &ds){
        //base case
        //when the combination ds is carrying is a valid one add it into th ans
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(index==candidates.size() || candidates[index]>target){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]<=target && (i==index || candidates[i]!=candidates[i-1])){
                ds.push_back(candidates[i]);
                helper(i+1, target-candidates[i], candidates, ans, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//sort the given candidates vector 
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0, target, candidates, ans, ds);
        return ans;
    }
};