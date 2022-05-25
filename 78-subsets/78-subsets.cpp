class Solution {
private:
    vector<vector<int>> res;
    
public:
    void solve(vector<int> &nums, vector<int> op, int index){
        if(index==nums.size()){
            res.push_back(op);
            return;
        }
        solve(nums,op,index+1);
        op.push_back(nums[index]);
        solve(nums,op,index+1);
        op.pop_back();
    }
    
    // void solve(vector<int>& nums, vector<int> op, int index){
    //     res.push_back(op);
    //     for(int i=index;i<nums.size();i++){
    //         op.push_back(nums[i]);
    //         solve(nums, op, i+1);
    //         op.pop_back();
    //     }
    // }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(nums, op, 0);
        return res;
    }
};