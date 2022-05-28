class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minSoFar = INT_MAX;
        
        // best possible profit at index i is when we subtract lowest value
        // to left of i from prices[i]. Compare this profit with maxProfit
        for(int i=0;i<prices.size();i++){
            minSoFar = min(minSoFar, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minSoFar);
        }
        return maxProfit;
    }
};