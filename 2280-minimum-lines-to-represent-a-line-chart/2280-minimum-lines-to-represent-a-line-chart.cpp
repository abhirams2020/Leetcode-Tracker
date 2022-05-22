class Solution {
public:
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() <= 1)
            return 0;
        vector<long double> slopes;
        sort(stockPrices.begin(),stockPrices.end());
        for(int i=0;i<stockPrices.size()-1;i++){
            long double currSlope = (long double)(stockPrices[i+1][1]-stockPrices[i][1])/(stockPrices[i+1][0]-stockPrices[i][0]);
            slopes.push_back(currSlope);
        }
        int count = 1;
        for(int i=0;i<slopes.size()-1;i++){
            if(slopes[i+1]!=slopes[i]){
                count++;
            }
        }
        return count;
    }

    // int minimumLines(vector<vector<int>>& stockPrices) {
    //     if(stockPrices.size() <= 1)
    //         return 0;
    //     vector<int> slopes;
    //     sort(stockPrices.begin(),stockPrices.end());
    //     int count = 1;
    //     for(int i=0;i<stockPrices.size()-2;i++){
    //         long x1=stockPrices[i][0], x2=stockPrices[i+1][0], x3=stockPrices[i+2][0];
    //         long y1=stockPrices[i][1], y2=stockPrices[i+1][1], y3=stockPrices[i+2][1];
    //         if( (y2-y1)*(x3-x2) != (y3-y2)*(x2-x1) ){
    //             count++;
    //         }
    //     }
    //     return count;
    // }
};