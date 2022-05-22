class Solution {
public:
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