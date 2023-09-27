class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> v;
        set<string> st(dictionary.begin(),dictionary.end());
        string temp = "";
        for(int i = 0;i<sentence.length();i++){
            if(sentence[i]==' '){
                v.push_back(temp);
                temp = "";
            }
            else temp += sentence[i];
        }
        v.push_back(temp);
        string ans = "";
        for(auto& it : v){
            string temp = "";
            for(int j = 0;j<it.length();j++){
                temp += it[j];
                if(st.find(temp)!=st.end()){
                    it = temp;
                    break;
                }
            }
        }
        for(auto& it : v){
            ans += (it + " ");
        }
        ans.pop_back();
        return ans;

    }
};