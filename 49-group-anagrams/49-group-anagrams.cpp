class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        // map[string] will give all anagrams of the string
        unordered_map<string, vector<string>> mp;
        
        for(int i=0;i<strs.size();i++){
            string tempstr = strs[i];
            sort(tempstr.begin(), tempstr.end());
            mp[tempstr].push_back(strs[i]);
        }
        
        for(auto i:mp){
            res.push_back(i.second);
        }
        
        return res;
    }
};