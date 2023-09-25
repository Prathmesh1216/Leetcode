class Solution {
public:
int scor(vector<int>& student,vector<int>& mentor){
    int sum=0;
    for(int i=0;i<student.size();i++) {
        if(mentor[i]==student[i]) sum++;
    }
   
    return sum;
}
int f(int idx,int mask,vector<vector<int>>& students,vector<vector<int>>& mentors){
    if (idx>=mentors.size() ) return 0;
   
    int ans = 0;
    for(int i=0;i<students.size();i++){
        if((mask & (1<<i))==0){
            int score=scor(mentors[idx],students[i]);
            ans=max(ans,score+f(idx+1,mask|(1<<i),students,mentors));
        }

    }
    return ans;

}
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        return f(0,0,students,mentors);
    }
};