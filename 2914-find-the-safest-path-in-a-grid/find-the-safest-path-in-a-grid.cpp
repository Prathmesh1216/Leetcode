class Solution {
public:
 int row[4]={0,-1,0,1};
int col[4]={-1,0,1,0};
bool check(int r,int c,int maxi,vector<vector<int>> &dist,vector<vector<int>> &vis){
     int n=dist.size();
        int m=dist.size();
        if(dist[r][c]<maxi) return false;
    vis[r][c]=1;
   
    if(r==n-1 && c==m-1 ) return dist[r][c]>=maxi;
    for(int i=0;i<4;i++){
        int nr=r+row[i];
        int nc=c+col[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && dist[nr][nc]>=maxi){
            
            if(check(nr,nc,maxi,dist,vis)) return true;

        }

    }
    
return false;

}
  
    int maximumSafenessFactor(vector<vector<int>>& grid) {
      
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
          if(grid[0][0]==1) return 0;
        if(grid[n-1][m-1]==1) return 0;
       queue<pair<int,int>> q;
       vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==1) {
                   dist[i][j]=0;
                   q.push({i,j});
               }
           }
       }
       while(!q.empty()){
           int r=q.front().first;
           int c=q.front().second;
           q.pop();
           for(int i=0;i<4;i++){
                int nr=r+row[i];
               int nc=c+col[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]>1+dist[r][c]){
            
          dist[nr][nc]=1+dist[r][c];
          q.push({nr,nc});

        }

           }
       }
   int l=0;
   int h=n*m;
       
        while(l<=h){
            int mid=l+(h-l)/2;
            vector<vector<int>> vis(n,vector<int> (m,0));
            if(check(0,0,mid,dist,vis)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }

       return ans; 
        
    }
};