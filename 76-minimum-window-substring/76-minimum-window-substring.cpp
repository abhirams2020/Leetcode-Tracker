class Solution {
public:
/*  
    table[s[l]]++ is increasing the value of the characters which were reduced by table[s[r]]--. 
    So it will return to original value in case of characters not in string t, ie 0. 
    Characters which were in string t will get back the original values. ie. table[A = B = C] = 2. 
    So table[s[l]] will never be +ve in case of other characters. 
*/
    
    // USING VECTOR MAP
    
    string minWindow(string searchString, string t) {

        // Our hashtable of characters filled with occurences in our string
        vector<int> table(128, 0);
        
        // Store the frequency of characters in string t
        for(auto character : t) {
            table[character]++;
        }

        int start = 0;
        int end = 0;
        int counter = t.size();
        int startMin = 0;
        int minLen = INT_MAX;

        // Here we use the 2 pointer approach sliding window and rolling hash
        while(end < searchString.size()) {

            if(table[searchString[end]] > 0) {
                counter--;
            }
            table[searchString[end]]--;
            end++;

            while(counter == 0) {
                if(end - start < minLen) {
                    startMin = start;
                    minLen = end - start;
                }
    
                table[searchString[start]]++;
                if(table[searchString[start]] > 0) {
                    counter++;
                }
                start++;
            }
        }

        // Case when no substring satisfies
        if(minLen == INT_MAX) {
          return "";
        }

        return searchString.substr(startMin, minLen);
    }
};