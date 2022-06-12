class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int i = 0;
        double tax = 0;
        int prev = 0;
        for(int i=0;i<brackets.size() && income>prev;i++){
            int currRange = min(income,brackets[i][0]) - prev;
            tax += currRange * brackets[i][1] / 100.0;
            prev = brackets[i][0];
        }
        return tax;
    }
};