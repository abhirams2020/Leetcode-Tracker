class Solution {
public:
    int sumOfDigitSq(int n){
        int sum = 0;
        while(n>0){
            int rem = n%10;
            sum += rem*rem;
            n = n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        unordered_set<int> s;
        while(!s.count(n)){
            s.insert(n);
            n = sumOfDigitSq(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
};