class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>=b[0];
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string>p(positive_feedback.begin(),positive_feedback.end()),n(negative_feedback.begin(),negative_feedback.end());
        vector<vector<int>>s;
        for(int i=0;i<report.size();i++){
            string w=report[i]+" ";
            string tmp="";
            int score=0;
            for(auto j:w){
                if(j!=' ')
                    tmp+=j;
                else{
                    if(p.find(tmp)!=p.end())
                        score+=3;
                    if(n.find(tmp)!=n.end())
                        score-=1;
                    tmp="";    
                }
            }
            s.push_back({score,student_id[i]});
            
        }
        sort(s.begin(),s.end(),comp);
         vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(s[i][1]);
        return ans;
        
        
    }
};