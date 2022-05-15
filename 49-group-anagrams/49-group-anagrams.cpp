class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(auto i:strs){
            vector<int> v(26,0);
            for(auto c:i){
                v[c-'a']++;
            }
            mp[v].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i:mp){
            vector<string> v;
            for(auto s:i.second){
                v.push_back(s);
            }
            res.push_back(v);
        }
        return res;
    }
};