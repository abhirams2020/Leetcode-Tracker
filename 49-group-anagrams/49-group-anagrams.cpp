class Solution {
public:

//     string getkey(string &str){
//         string res;
//         vector<int> count(26,0);
//         for(auto i:str){
//             count[i-'a']++;
//         }
//         for(int i=0;i<26;i++){
//             for(int j=0;j<count[i];j++){
//                 res.push_back(char('a'+i));
//             }
//         }
//         return res;
//     }

//     vector<vector<string>> groupAnagrams(vector<string> &strs){
//         vector<vector<string>> res;
//         unordered_map<string,vector<string>> mp;
//         for(int i=0;i<strs.size();i++){
//             mp[getkey(strs[i])].push_back(strs[i]);
//         }
//         for(auto i:mp){
//             res.push_back(i.second);
//         }
//         return res;
//     }
    
    vector<vector<string>> groupAnagrams(vector<string> strs){
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        for(auto i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};