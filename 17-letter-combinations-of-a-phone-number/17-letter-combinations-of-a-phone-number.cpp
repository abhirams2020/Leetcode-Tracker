class Solution {
public:
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    
    void dfs(string digits, string op, int index){
        if(index==digits.length()){
            res.push_back(op);
            return;
        }
        int curr = digits[index] - '0';
        for(auto c:mapping[curr]){
            op.push_back(c);
            dfs(digits,op,index+1);
            op.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return res;
        }
        string op="";
        dfs(digits,op,0);
        return res;
    }
};