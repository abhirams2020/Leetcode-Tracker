class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        int maxSize = 1;
        
        // Add all elements into a set
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        
        // choose an element in the set and initialise size as 1
        // erase all consecutive elements less than curr and increment the size
        // erase all consecutive elements greater than curr and increment the size
        // compare maxSize and size
        while(!s.empty()){
            int curr = *s.begin();
            int size = 1;
            int num = curr;
            s.erase(curr);
            while(s.count(num-1)){
                size++;
                s.erase(num-1);
                num--;
            }
            num = curr;
            while(s.count(num+1)){
                size++;
                s.erase(num+1);
                num++;
            }
            maxSize = max(maxSize,size);
        }
        
        return maxSize;
    }
};