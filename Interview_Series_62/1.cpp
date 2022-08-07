class Solution{
    public:
    bool wifiRange(int n, string s, int x){
          int i=0;
          vector<int>vis(n+1,0);
          while(i<n){
               if(s[i]=='1'){
                    int mi=max(i-x,0);
                    int ma=min(i+x+1,n);
                    vis[mi]+=1;
                    vis[ma]-=1;
               }
               i++;
          }
          vector<int>ans;
          for(int i=0;i<n;i++){
               if(s[i]=='1'){
                   ans.push_back(1);
               }
               else{
                   ans.push_back(0);
               }
          }
          int temp=0;
          for(int i=0;i<n;i++){
              temp+=vis[i];
              ans[i]+=temp;
          }
          for(int i=0;i<n;i++){
           //    cout<<ans[i]<<" ";
               if(ans[i]==0) return false;
          }
        
          
        return true;
    }
};