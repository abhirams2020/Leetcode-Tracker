class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double num = myPow(x,n/2);
        if(n%2==0){
            return num * num;
        }
        else {
            if(n < 0){
                return 1/x * num * num;
            }
            else {
                return x * num * num;
            }
        }
        return -1;
    }
};