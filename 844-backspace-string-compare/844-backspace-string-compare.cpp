class Solution {
public:
    bool backspaceCompare(string s1, string s2) {
        string res1, res2;
        int i=0;
        while(i<s1.length()){
            if(!res1.empty() && s1[i]=='#'){
                res1.pop_back();
            }
            else if(s1[i]!='#'){
                res1.push_back(s1[i]);
            }
            i++;
        }
        i=0;
        while(i<s2.length()){
            if(!res2.empty() && s2[i]=='#'){
                res2.pop_back();
                
            }
            else if(s2[i]!='#'){
                res2.push_back(s2[i]);
            }
            i++;
        }
        cout<<res1<<" "<<res2<<endl;
        return res1==res2;
    }
};