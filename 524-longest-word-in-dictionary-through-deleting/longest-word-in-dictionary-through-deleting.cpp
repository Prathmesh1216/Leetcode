class Solution {
public:
    static bool cmp(string& a,string& b){
        if(a.length()==b.length()) return a<b;
        return a.length()>b.length();
    }
   // vector<int> freq;
    bool isValid(string& a,string& b){
        int i = 0;
        int j = 0;
        while(j<b.length() && i<a.length()){
            if(a[i]==b[j]){
                i++;
                // j++;
            }
            j++;
           
        }
        if(i==a.length()) return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);
        for(auto it : dictionary){
            if(isValid(it,s)) return it;
        }
        return "";
    }
};