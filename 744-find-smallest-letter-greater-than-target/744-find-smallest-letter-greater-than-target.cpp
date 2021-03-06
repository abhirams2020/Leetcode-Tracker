class Solution {
public:
    // // naive solution O(n)
    // char nextGreatestLetter(vector<char>& letters, char target) {
    //     char minchar;
    //     unordered_set<char> s;
    //     for(auto i:letters){
    //         s.insert(i);
    //     }
    //     int index = target - 'a';
    //     while(1){
    //         if(s.find('a'+index)!=s.end() && target!='a'+index){
    //             minchar = 'a' + index;
    //             break;
    //         }
    //         index = (index+1)%26;
    //     }
    //     return minchar;
    // }
    

    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        if(target<letters[0] || target>=letters[size-1]){
            return letters[0];
        }
        int l=0,r=size-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(letters[mid] <= target){
                l = mid+1;
            }
            else {
                // r can be next greatest so min-1 not possible
                r = mid;
            }
        }
        return letters[r];
    }
};