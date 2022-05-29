class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> mp;
        for(int i=0;i<num.length();i++){
            mp[i]=0;
        }
        for(auto i:num){
            mp[i-'0']++;
        }
        for(int i=0;i<num.length();i++){
            if(mp[i]!=num[i]-'0'){
                return false;
            }
        }
        return true;
    }
};