class Solution {
public:
//     // O(N) soln but using long double
    
//     int minimumLines(vector<vector<int>>& stockPrices) {
//         if(stockPrices.size() <= 1)
//             return 0;
//         vector<long double> slopes;
//         sort(stockPrices.begin(),stockPrices.end());
//         int count = 1;
//         long double prevSlope=(long double)(stockPrices[1][1]-stockPrices[0][1])/(stockPrices[1][0]-stockPrices[0][0]);
//         for(int i=2;i<stockPrices.size();i++){
//             long double currSlope = (long double)(stockPrices[i][1]-stockPrices[i-1][1])/(stockPrices[i][0]-stockPrices[i-1][0]);
//             if(currSlope!=prevSlope){
//                 prevSlope = currSlope;
//                 count++;
//             }
//         }
//         return count;
//     }
    
    // O(N) soln using long only
    // instead of (y2-y1)/(x2-x1) = (y3-y2)/(x3-x2) we do (y2-y1)*(x3-x2) = (y3-y2)*(x2-x1)
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() <= 1)
            return 0;
        vector<int> slopes;
        sort(stockPrices.begin(),stockPrices.end());
        int count = 1;
        for(int i=0;i<stockPrices.size()-2;i++){
            long x1=stockPrices[i][0], x2=stockPrices[i+1][0], x3=stockPrices[i+2][0];
            long y1=stockPrices[i][1], y2=stockPrices[i+1][1], y3=stockPrices[i+2][1];
            if( (y2-y1)*(x3-x2) != (y3-y2)*(x2-x1) ){
                count++;
            }
        }
        return count;
    }
};