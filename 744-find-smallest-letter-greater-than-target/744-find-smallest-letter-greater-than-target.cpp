class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char minchar;
        unordered_set<char> s;
        for(auto i:letters){
            s.insert(i);
        }
        int index = target - 'a';
        while(1){
            if(s.find('a'+index)!=s.end() && target!='a'+index){
                minchar = 'a' + index;
                break;
            }
            index = (index+1)%26;
        }
        return minchar;
    }
};