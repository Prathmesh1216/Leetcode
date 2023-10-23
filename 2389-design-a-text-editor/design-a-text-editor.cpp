class TextEditor {
public:
    string ls = "", rs = "";
    TextEditor() {
        
    }
    
    void addText(string text) {
        ls += text; 
    }
    int deleteText(int k) {
        k = min(k,(int)ls.size());
        ls.resize(ls.size()-k);
        return k;
    }
    string cursorLeft(int k) {
        while(k>0 && !ls.empty()){
            rs.push_back(ls.back());
            ls.pop_back();
            k--;
        }
        return ls.size()>=10 ? ls.substr(ls.size()-10,10):ls;
    }
    string cursorRight(int k) {
        while(k>0 && !rs.empty()){
            ls.push_back(rs.back());
            rs.pop_back();
            k--;
        }
        return ls.size()>= 10 ? ls.substr(ls.size()-10,10):ls;
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