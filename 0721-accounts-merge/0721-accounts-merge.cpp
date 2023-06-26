class Solution {
public:
       vector<int>parant,size;
    int find_set(int v){
        if(v==parant[v]){
            return v;
        }
        return parant[v]=find_set(parant[v]);
    }
    void make_union(int u,int v){
        int x=find_set(u);
        int y=find_set(v);
        
        if(x==y){
            return;
        }
        if(size[x]<size[y]){
            parant[x]=y;
            size[y]+=size[x];
        }
        else{
            parant[y]=x;
        size[x]+=size[y];
        }
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parant.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parant[i]=i;
            size[i]=1;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
               string mail=accounts[i][j];
                if(mp.find(mail)!=mp.end()){
                     make_union(mp[mail],i); //email-->i
                }
                else{
                    mp[accounts[i][j]]=i;
                   
                }
                
            }
        }
        vector<string>merger[n];
        for(auto it:mp){
            
            string email=it.first;
             int new_par=find_set(it.second);
            merger[new_par].push_back(email);
        }
        
        vector<vector<string>>ans;
           for(int i=0;i<n;i++){
            if(merger[i].size()==0) continue;

            sort(merger[i].begin(),merger[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it :merger[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};