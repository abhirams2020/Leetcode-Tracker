class Solution {
public:
//     void permute(string ip,string op,vector<string>& ans){
//         if(ip.length()==0){
//             ans.push_back(op);
//             return;
//         }
//         if(isalpha(ip[0])){
//             permute(ip.substr(1),op+(char)tolower(ip[0]),ans);
//             permute(ip.substr(1),op+(char)toupper(ip[0]),ans);
//         }
//         else {
//             permute(ip.substr(1),op+ip[0],ans);
//         }
//     }
    
//     vector<string> letterCasePermutation(string s) {
//         vector<string> ans;
//         string op;
//         permute(s,op,ans);
//         return ans;
//     }

    void permute(string& s,int index,vector<string>& ans){
        if(index==s.length()){
            ans.push_back(s);
            return;
        }
        if(isalpha(s[index])){
            s[index] = tolower(s[index]);
            permute(s,index+1,ans);
            s[index] = toupper(s[index]);
            permute(s,index+1,ans);
        }
        else {
            permute(s,index+1,ans);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        permute(s,0,ans);
        return ans;
    }
};