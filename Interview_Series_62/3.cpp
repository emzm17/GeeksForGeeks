class Solution {
public:
     int dx[4]={-1,0,1,0};
     int dy[4]={0,-1,0,1};
    int n,m;
    bool v(int i,int j,vector<vector<int>>&vis,int n,int m){
            if(i<1 or i>n or j<1 or j>m or vis[i][j]==1) return false;
            return true;
    }
     int bfs( queue<pair<int,pair<int,int>>>&q,vector<vector<int>>&vis,int n,int m){
          int dis=0;
          while(!q.empty()){
                pair<int,pair<int,int>>p=q.front();
                q.pop();
                dis=p.first;
                int x=p.second.first;
                int y=p.second.second;
               // cout<<dis<<" "<<x<<" "<<y<<"\n";
                for(int i=0;i<4;i++){
                      if(v(dx[i]+x,dy[i]+y,vis,n,m)){
                          q.push({dis+1,{dx[i]+x,dy[i]+y}});
                           vis[dx[i]+x][dy[i]+y]=1;
                      }
                }
          }
         return dis; 
     }


    
    int solve(int N, int M, int k, vector<vector<int> >v) {
        vector<vector<int>>vis(N+1,vector<int>(M+1,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<k;i++){
             q.push({0,{v[i][0],v[i][1]}});
             vis[v[i][0]][v[i][1]]=1;
        }
        int cnt=bfs(q,vis,N,M);
        return cnt;
    }
};
