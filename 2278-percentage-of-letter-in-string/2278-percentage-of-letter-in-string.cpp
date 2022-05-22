class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for(auto i:s){
            if(i==letter){
                count++;
            }
        }
        return count*100/s.length();
    }
};