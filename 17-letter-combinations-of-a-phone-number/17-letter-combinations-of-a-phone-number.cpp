class Solution {
public:

    
    vector<string> ans;
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string& digits, int index, string& op){
        if(index==digits.size()){
            if(op!="")
                ans.push_back(op);
            return;
        }
        for(int i=0;i<mp[(digits[index])-'0'].length();i++){
            op.push_back(mp[(digits[index])-'0'][i]);
            solve(digits,index+1,op);
            op.pop_back();
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
        solve(digits,0,op);
        return ans;
    }
};