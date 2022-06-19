class Solution {
public:
    int solve(string s, int index, int sum){
        int len = 0;
        int p = 0;
        for(int i=index;i<=s.length();i++){
            int val = s[i]-'0';
            long double curr = val * pow(2,p);
            if(val==1 && curr<=sum){
                sum-=curr;
                len++;
            }
            else if(val==0){
                len++;
            }
            p++;
        }
        return len;
    }
    int longestSubsequence(string s, int sum) {
        reverse(s.begin(),s.end());
        int ans = 0;
        for(int i=0;i<s.length();i++){
            ans = max(ans, solve(s,i,sum));
        }
        return ans;
    }
};