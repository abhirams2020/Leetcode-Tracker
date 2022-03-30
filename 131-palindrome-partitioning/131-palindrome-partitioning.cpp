class Solution {
public:
//     vector<vector<string>> res;
    
//     bool checkPal(string str){
//         int left = 0, right = str.length()-1;
//         while(left<right){
//             if(str[left]!=str[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
    
//     void solve(string str, vector<string> &op){
//         if(str==""){
//             res.push_back(op);
//             return;
//         }
//         for(int i=0;i<str.length();i++){
//             if(checkPal(str.substr(0,i+1))){
//                 op.push_back(str.substr(0,i+1));
//                 solve(str.substr(i+1),op);
//                 op.pop_back();
//             }
//         }
//     }
    
//     vector<vector<string>> partition(string s) {
//         vector<string> op;
//         solve(s,op);
//         return res;
//     }
    
    vector<vector<string>> res;
    
    map<pair<int,int>,bool> dp;
    
    bool checkPal(string str, int left, int right){
        if(dp.find(make_pair(left,right))!=dp.end()){
            return dp[make_pair(left,right)];
        }
        while(left<right){
            if(str[left]!=str[right]){
                return dp[make_pair(left,right)] = false;
            }
            left++;
            right--;
        }
        return dp[make_pair(left,right)] = true;
    }
    
    void solve(string str, int index, vector<string> &op){
        if(index==str.length()){
            res.push_back(op);
            return;
        }
        for(int i=index;i<str.length();i++){
            if(checkPal(str,index,i)){
                op.push_back(str.substr(index,i-index+1));
                solve(str,i+1,op);
                op.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> op;
        solve(s,0,op);
        return res;
    }
};