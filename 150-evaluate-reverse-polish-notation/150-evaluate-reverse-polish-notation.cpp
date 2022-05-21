class Solution {
public:
    int calculate(int first, int second, string op){
        int ans = 0;
        if(op=="+"){
            ans = first+second;
        }
        else if(op=="-"){
            ans = first-second;
        }
        else if(op=="*"){
            ans = first*second;
        }
        else if(op=="/"){
            ans = first/second;
        }
        return ans;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens){
            if(i=="+" || i=="-" || i=="*" || i=="/"){
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(calculate(first,second,i));
            }
            else {
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};