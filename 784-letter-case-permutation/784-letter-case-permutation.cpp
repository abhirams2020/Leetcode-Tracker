class Solution {
public:
    
    void permute(string ip,string op,vector<string>& ans){
        if(ip.length()==0){
            ans.push_back(op);
            return;
        }
        if(isalpha(ip[0])){
            permute(ip.substr(1),op+(char)tolower(ip[0]),ans);
            permute(ip.substr(1),op+(char)toupper(ip[0]),ans);
        }
        else {
            permute(ip.substr(1),op+ip[0],ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string op;
        permute(s,op,ans);
        return ans;
    }
};