class Solution {
public:
    bool isValid(string str) {
        if(str.length()%2){
            return false;
        }
        map<char,char> mp = {{')','('}, {']','[' }, {'}','{'}};
        stack<char> st;
        set<char> s = {'(','[','{'};
        for(char ch:str) {
            if(s.count(ch)) {
                st.push(ch);
            }
            else {
                if(st.empty() || st.top()!=mp[ch]){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};