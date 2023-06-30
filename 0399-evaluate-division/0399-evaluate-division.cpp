class Solution {
public:
    void dfs(string start,string end,unordered_map<string,bool>& vis,unordered_map<string,double>&mp,unordered_map<string,vector<string>>&adj,bool &found,double &val){
        vis[start]=true;
        if(found==true){
            return;
        }
        for(auto it:adj[start]){
            if(!vis[it]){
                val=val*mp[start+"->"+it];
                if(it==end){
                    found=true;
                    return;
                }
                dfs(it,end,vis,mp,adj,found,val);
                 if(found==true){
                    return ;
                }
                else{
                    val/=mp[start+"->"+it];
                }
            }
        }
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>res;
        unordered_map<string,double>mp;
        unordered_map<string,vector<string>>adj;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1.0/values[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(adj.find(start)==adj.end() || adj.find(end)==adj.end()){
                res.push_back(-1.0);
            }
            else{
                unordered_map<string,bool>vis;
                bool found=false;
                double val=1.0;
                if(start==end){
                    found=true;
                }
                dfs(start,end,vis,mp,adj,found,val);
                if(found==true){
                    res.push_back(val);
                }
                else{
                    res.push_back(-1.0);
                }
            }
        }
        return res;
    }
};