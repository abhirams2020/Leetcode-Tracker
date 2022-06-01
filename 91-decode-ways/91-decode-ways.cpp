class Solution {
public:
    // dp stores no of ways from start pointer
    vector<int> dp;
    
    bool isValid(string &s, int start, int end){
        string str = s.substr(start,end-start+1);
        // valid is 1,2,3...9, 10,11,...,19, 20,21,...,26
        // number starting with 0 not valid
        if(str[0]=='0'){
            return false;
        }
        // if 2 digit number start with 3 or more, invalid
        // if 2 digit number start with 2 and more than 6, invalid.
        if(str.length()==2 && (str[0]>='3' || (str[0]=='2' && str[1]>'6'))){
            return false;
        }
        return true;
    }
    
    int solve(string &s, int start, int end){
        // if start more than end, means all substrings were decoded
        if(start>end){
            return 1;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        int count = 0;
        // count possibilities if we take 1 char from start or 2 chars from start
        for(int i=start;i<=end && i<=start+1;i++){
            if(isValid(s,start,i)){
                count += solve(s,i+1,end);
            }
        }
        return dp[start] = count;
    }
    
    int numDecodings(string s) {
        dp.resize(s.length()+1, -1);
        return solve(s,0,s.length()-1);
    }
};