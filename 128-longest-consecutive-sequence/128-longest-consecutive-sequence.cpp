class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        int maxSize = 1;
        
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        
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