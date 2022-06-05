class TextEditor {
public:
    deque<char> rightStr;
    deque<char> leftStr;
    
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto i:text){
            leftStr.push_back(i);            
        }
    }
    
    int deleteText(int k) {
        if(k>=leftStr.size()){
            int len = leftStr.size();
            leftStr.clear();
            return len;
        }
        for(int i=0;i<k;i++){
            leftStr.pop_back();
        }
        return k;
    }
    
    string cursorLeft(int k) {
        int size = leftStr.size();
        for(int i=0;i<min(k,size);i++){
            rightStr.push_front(leftStr[leftStr.size()-1]);
            leftStr.pop_back();                
        }
        int start = max(0,int(leftStr.size()-10));
        string op;
        for(int i=start;i<leftStr.size();i++){
            op.push_back(leftStr[i]);
        }
        return op;
    }
    
    string cursorRight(int k) {
        int size = rightStr.size();
        for(int i=0;i<min(k,size);i++){
            leftStr.push_back(rightStr[0]);
            rightStr.pop_front();
        }
        int start = max(0,int(leftStr.size()-10));
        string op;
        for(int i=start;i<leftStr.size();i++){
            op.push_back(leftStr[i]);
        }
        return op;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */