class Solution {
public:
static bool cmp(vector<int> &a,vector<int> &b){
    if(a[1]==b[1]) return a[2]<b[2];
    return a[1]<b[1];
}
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        map<int,int> m;// des,passenger
        int cap=0;
      
        
        for(int i=0;i<trips.size();i++){
            vector<int> temp2=trips[i];
           
    
                for(auto it:m){
                  cout<<"12";
                    if(it.first<=temp2[1]) {
                        cap-=it.second;
                       
                        m.erase(it.first);
                    }
                }
               
            
        
           
                if(cap+temp2[0]>capacity) return false;
                cap+=temp2[0];
                cout<<endl;
                cout<<"caps"<<cap<<endl;
                
            
            m[temp2[2]]+=temp2[0];

        }
    
        return true;
    }
};