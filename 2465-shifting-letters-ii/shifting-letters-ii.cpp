class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v(s.length()+1,0);
        for(auto& it : shifts){
            if(it[2]==1){
                v[it[0]]++;
                v[it[1]+1]--;
            }
            else{
                v[it[0]]--;
                v[it[1]+1]++;
            }
        }
        int sum = 0;
        for(int i = 0;i<s.length();i++){
            sum += v[i];
            int k = sum%26;
            s[i] = 'a' + ((s[i]-'a')+k+26)%26;
        }
        return s;
    }
};