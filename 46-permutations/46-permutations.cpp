class Solution {
public:
    
    void solve(vector<int>&nums, int start, vector<vector<int>> &res){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            solve(nums,start+1,res);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums,0,res);
        return res;
    }
};

// class Solution {
// public:
    
//     // permute num[begin..end]
//     // invariant: num[0..begin-1] have been fixed/permuted
// // 	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
// // 		if (begin == num.size()) {
// // 		    // one permutation instance
// // 		    result.push_back(num);
// // 		    return;
// // 		}
		
// // 		for (int i = begin; i < num.size(); i++) {
// // 		    swap(num[begin], num[i]);
// // 		    permuteRecursive(num, begin + 1, result);
// // 		    swap(num[begin], num[i]);
// // 		}
// //     }
//     void permuteRecursive(vector<int>&nums, int start, vector<vector<int>> &res){
//         if(start>=nums.size()){
//             res.push_back(nums);
//             return;
//         }
        
//         for(int i=start;i<nums.size();i++){
//             swap(nums[start],nums[i]);
//             permuteRecursive(nums,start+1,res);
//             swap(nums[start],nums[i]);
//         }
//     }
    
//     vector<vector<int> > permute(vector<int> &num) {
// 	    vector<vector<int>> result;
	    
// 	    permuteRecursive(num, 0, result);
// 	    return result;
//     }
// };