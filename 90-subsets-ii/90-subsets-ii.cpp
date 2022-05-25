class Solution {
private:
    vector<vector<int>> res;
    
public:
    void solve(vector<int> &nums, vector<int> op, int index){
        res.push_back(op);
        for(int i=index;i<nums.size();i++){
            // if next element is equal to curr element there will be repetition
            // ie. {1,2,2}. current op is {1}. if we add 2 repeatedly, op will be {1,2} and {1,2}
            if(i==index || nums[i]!=nums[i-1]){
                op.push_back(nums[i]);
                solve(nums,op,i+1);
                op.pop_back();                
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> op;
        sort(nums.begin(), nums.end());
        solve(nums, op, 0);
        return res;
    }
};