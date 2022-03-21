class Solution {
public:
//     bool backspaceCompare(string s1, string s2) {
//         string res1, res2;
//         int i=0;
//         while(i<s1.length()){
//             if(!res1.empty() && s1[i]=='#'){
//                 res1.pop_back();
//             }
//             else if(s1[i]!='#'){
//                 res1.push_back(s1[i]);
//             }
//             i++;
//         }
//         i=0;
//         while(i<s2.length()){
//             if(!res2.empty() && s2[i]=='#'){
//                 res2.pop_back();
                
//             }
//             else if(s2[i]!='#'){
//                 res2.push_back(s2[i]);
//             }
//             i++;
//         }
//         cout<<res1<<" "<<res2<<endl;
//         return res1==res2;
//     }

    bool backspaceCompare(string s1, string s2) {
        int r1=0,r2=0;
        int curr=0;
        while(curr<s1.length()){
            if(r1!=0 && s1[curr]=='#'){
                r1--;
            }
            else if(s1[curr]!='#'){
                s1[r1] = s1[curr];
                r1++;
            }
            curr++;
        }
        curr=0;
        while(curr<s2.length()){
            if(r2!=0 && s2[curr]=='#'){
                r2--;
            }
            else if(s2[curr]!='#'){
                s2[r2] = s2[curr];
                r2++;
            }
            curr++;
        }
        // print string
        for(int i=0;i<r1;i++){
            cout<<s1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<r2;i++){
            cout<<s2[i]<<" ";
        }
        // check if both are equal
        
        if(r1!= r2){
            return false;
        }
        for(int i=0, j=0; i<r1,j<r2; i++,j++){
            if(s1[i]!=s2[j]){
                return false;
            }
        }
        return true;
    }
};