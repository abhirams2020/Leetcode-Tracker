class Solution {
public:
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() <= 1)
            return 0;
        vector<long double> slopes;
        sort(stockPrices.begin(),stockPrices.end());
        int count = 1;
        long double prevSlope=(long double)(stockPrices[1][1]-stockPrices[0][1])/(stockPrices[1][0]-stockPrices[0][0]);
        
        for(int i=2;i<stockPrices.size();i++){
            long double currSlope = (long double)(stockPrices[i][1]-stockPrices[i-1][1])/(stockPrices[i][0]-stockPrices[i-1][0]);
            if(currSlope!=prevSlope){
                prevSlope = currSlope;
                count++;
            }
        }
        
        return count;
    }
};