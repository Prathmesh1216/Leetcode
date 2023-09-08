class Solution {
public:
    int n;
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        n = tokens.size();
        int i = 0;
        int j = n-1;
        int score = 0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            else{
                if(score>=1 && j-i>1) power+=tokens[j],score--,j--;
                else i++;
            }
        }
        return score;
    }
};