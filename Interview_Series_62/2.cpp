class Solution {
  public:
   
    string removeReverse(string s) {
       map<char,int>mp;
       for(int i=0;i<s.size();i++){
          mp[s[i]]++;
       }
       int i,j;
       i=0;
       j=s.size()-1;
       bool flag=false;
       while(i<=j){
         if(flag==false){
           if(mp[s[i]]>1){
               mp[s[i]]-=1;
               s[i]='0';
               i++;
               flag=true;
           }
           else{
               i++;
               continue;
           }
        }
        else{
             if(mp[s[j]]>1){
                 mp[s[j]]-=1;
                 s[j]='0';
                  j--;
                 flag=false;
             }
             else{
                 j--;
                 continue;
             }
        }
       }
       string ans="";
       if(!flag)
       for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ans+=s[i];
            }
       }
       else{
           for(int i=s.size()-1;i>=0;i--){
                if(s[i]!='0'){
                    ans+=s[i];
                }
           }
       }
        
          return ans;
       
    }
};