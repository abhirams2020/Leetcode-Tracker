class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void dfs(string s, vector<string> &op, int index){
        if(index==s.length()){
            res.push_back(op);
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                op.push_back(s.substr(index, i-index+1));
                dfs(s, op, i+1);
                op.pop_back();                
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> op;
        dfs(s,op,0);
        return res;
    }
};