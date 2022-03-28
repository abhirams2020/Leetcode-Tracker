class Solution {
public:

    
    vector<string> ans;
    
    void solve(string& digits,unordered_map<char,string> &mp, int index, string& op){
        if(index==digits.size()){
            if(op!="")
                ans.push_back(op);
            return;
        }
        for(int i=0;i<mp[digits[index]].length();i++){
            // if(mp.find(digits[index])!=mp.end()){
                op.push_back(mp[digits[index]][i]);
                solve(digits,mp,index+1,op);
                op.pop_back();                
            // }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string op = "";
        solve(digits,mp,0,op);
        return ans;
    }
};