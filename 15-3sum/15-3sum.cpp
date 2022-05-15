class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> res;
        int l=start, r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r] == target){
                vector<int> temp;
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                res.push_back(temp);
                l++;
                r--;
            }
            else if(nums[l]+nums[r] < target){
                l++;
            }
            else if(nums[l]+nums[r] > target){
                r--;
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0){
            return res;
        }
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            vector<vector<int>> temp;
            temp = twoSum(nums,i+1,-nums[i]);
            for(auto v:temp){
                if(v.size()!=0){
                    v.push_back(nums[i]);
                    st.insert(v);
                }
            }
        }
        for(auto i:st){
            res.push_back(i);
        }
        return res;
    }
};