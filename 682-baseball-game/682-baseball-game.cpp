class Solution {
public:
    
    // int tostring(string s){
    //     int i=0;
    //     int ans = 0;
    //     int sign = 1;
    //     if(s[0]=='-'){
    //         sign = -1;
    //         i = 1;
    //     }
    //     while(i<s.length()){
    //         ans = ans*10 + (s[i]-'0');
    //         i++;
    //     }
    //     return sign*ans;
    // }
    
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        int len = 0;
        for(auto i:ops){
            if(i=="C"){
                ans.pop_back();
                len--;
            }
            else if(i=="D"){
                ans.push_back(2*ans[ans.size()-1]);
                len++;
            }
            else if(i=="+"){
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
                len++;
            }
            else {
                // ans.push_back(tostring(i));
                // use stoi fn to convert string to integer
                ans.push_back(stoi(i));
                len++;
            }
        }
        int sum = 0;
        for(auto i:ans){
            sum += i;
        }
        return sum;
    }
};