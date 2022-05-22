class Solution {
public:
    int solve(int n, vector<int> &rem, int additionalRocks){
        if(additionalRocks==0 || rem.size()==0){
            return 0;
        }
        int count = 0;
        for(int i=0;i<rem.size();i++){
            if(additionalRocks >= rem[i]){
                additionalRocks = additionalRocks-rem[i];
                count++;
            }
            else
                break;
        }
        return count;
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> rem;
        for(int i=0;i<capacity.size();i++){
            rem.push_back(capacity[i]-rocks[i]);
        }
        sort(rem.begin(),rem.end());
        int full = solve(capacity.size(),rem,additionalRocks);
        return full;
    }
};