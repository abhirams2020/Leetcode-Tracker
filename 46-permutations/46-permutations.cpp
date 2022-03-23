class Solution {
public:
    
    int fact(int n){
        if(n==0 || n==1){
            return 1;
        }
        return n * fact(n-1);
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i=0;i<fact(nums.size());i++){
            next_permutation(nums.begin(),nums.end());
            res.push_back(nums);
        }
        return res;
    }
};