class Solution {
public:
    int count1s(int n){
        if(n==0){
            return 0;
        }
        return (n&1) + count1s(n>>1);
    }
    
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(count1s(i));
        }
        return res;
    }
};