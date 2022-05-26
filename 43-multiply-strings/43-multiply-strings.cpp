class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        
        // Max possible size of product will be m+n
        int m=num1.length(), n=num2.length();
        vector<int> arr(m+n,0);
        
        // Do reverse traversal and update the digit places
        // Carry of i'th position is added to i-1'th position
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int currPos = i+j+1, prevPos = i+j;
                
                int sum = arr[currPos] + (num1[i]-'0')*(num2[j]-'0');
                arr[currPos] = sum%10;
                arr[prevPos] += sum/10;
            }
        }
        
        string res;
        
        for(int i=0;i<m+n;i++){
            // Skip leading zeroes
            if(res.empty() && arr[i]==0){
                continue;
            }
            else {
                res.push_back('0'+arr[i]);
            }
        }
        return res;
    }
};