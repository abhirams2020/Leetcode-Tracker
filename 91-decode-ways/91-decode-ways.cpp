class Solution {
public:
    vector<int> dp;
    
    bool isValid(string &s, int start, int end){
        string str = s.substr(start,end-start+1);
        // valid is 1,2,3...9, 10,11,...,19, 20,21,...,26
        if(str[0]=='0'){
            return false;
        }
        if(str.length()==2 && (str[0]>='3' || (str[0]=='2' && str[1]>'6'))){
            return false;
        }
        return true;
    }
    
    int solve(string &s, int start, int end){
        if(start>end){
            return 1;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        int count = 0;
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