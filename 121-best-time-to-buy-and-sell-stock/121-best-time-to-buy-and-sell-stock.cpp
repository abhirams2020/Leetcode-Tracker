class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int maxProf = 0;
        for(int i=1;i<prices.size();i++){
            minSoFar = min(prices[i],minSoFar);
            maxProf = max(prices[i]-minSoFar, maxProf);
        }
        return maxProf;
    }
};