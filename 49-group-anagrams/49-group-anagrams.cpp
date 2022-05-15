class Solution {
public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res;
//         unordered_map<string, vector<string>> mp;
//         for(auto i:strs){
//             string s = i;
//             sort(s.begin(),s.end());
//             mp[s].push_back(i);
//         }
        
//         for(auto i:mp){
//             res.push_back(i.second);
//         }
//         return res;
//     }
    
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
            res.push_back(i.second);
        }
        return res;
    }
};