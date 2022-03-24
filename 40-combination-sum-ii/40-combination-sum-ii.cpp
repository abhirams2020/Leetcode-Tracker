// class Solution {
// public:
//     vector<vector<int>> res;
//     set<vector<int>> s;
    
//     void solve(vector<int> &candidates, int index, vector<int> op, int target){
//         if(target==0){
//             if(s.count(op)==0)
//                 s.insert(op);
//             return;
//         }
//         if(index==candidates.size()){
//             return;
//         }
//         if(candidates[index] <= target){
//             solve(candidates,index+1,op,target);
//             op.push_back(candidates[index]);
//             solve(candidates,index+1,op,target-candidates[index]);
//         }
//         // else{
//         //     solve(candidates,index+1,op,target);
//         // }
//     }
    
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<int> op;
//         sort(candidates.begin(),candidates.end());
//         solve(candidates,0,op,target);
//         for(auto i:s){
//             res.push_back(i);
//         }
//         return res;
//     }
// };

class Solution {
public:
    void helper(int index, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int> &ds){
        //base case
        //when the combination ds is carrying is a valid one add it into th ans
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(index==candidates.size()){
            return;
        }
        if(candidates[index]>target){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            ds.push_back(candidates[i]);
            helper(i+1, target-candidates[i], candidates, ans, ds);
            ds.pop_back();
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