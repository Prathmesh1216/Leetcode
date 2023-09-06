class Solution {
public:
    int n;
    bool cantake(vector<int>& let,string& s){
        bool flag = true;
        for(int i = 0;i<s.length();i++){
            if(let[s[i]-'a']==0) flag = false;
            let[s[i]-'a']--;
        }
        for(int i = 0;i<s.length();i++){
            let[s[i]-'a']++;
        }

        return flag;
    }
    int solve(int i,vector<string>& words,vector<int>& score,vector<int>& let){
        if(i==n) return 0;
        bool flag = false;
        int ans2 = 0;
        if(cantake(let,words[i])){
            flag = true;
            for(int j = 0;j<words[i].length();j++){
                let[words[i][j]-'a']--;
                ans2+=score[words[i][j]-'a'];
            }
            ans2 += solve(i+1,words,score,let);
            for(int j = 0;j<words[i].length();j++){
                let[words[i][j]-'a']++;
            }
        }
        int ans1 = solve(i+1,words,score,let);
        if(flag) return max(ans1,ans2);
        return ans1;

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        vector<int> let(26);
        for(auto it : letters) let[it-'a']++;
        return solve(0,words,score,let);
    }
};