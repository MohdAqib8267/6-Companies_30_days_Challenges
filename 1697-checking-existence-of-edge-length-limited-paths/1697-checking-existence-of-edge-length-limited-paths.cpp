class Solution {
public:
    int find_parent(vector<int>& parent,int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=find_parent(parent,parent[v]);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<bool>ans(queries.size(),false);
        vector<pair<int,int>>Q;
        for(int i = 0; i < queries.size(); i++){
            Q.push_back({queries[i][2],i});
        }
        for(int i=0;i<edgeList.size();i++){
            swap(edgeList[i][0],edgeList[i][2]);
        }
        sort(edgeList.begin(),edgeList.end());
        sort(Q.begin(),Q.end());
        int j=0;
        for(int i=0;i<Q.size();i++){
            while(j<edgeList.size() and edgeList[j][0] < Q[i].first){
                int u = edgeList[j][1],v = edgeList[j][2];
                int pu=find_parent(parent,u);
                int pv=find_parent(parent,v);
                if(pu!=pv){
                    parent[pu]=pv;
                }
                j++;
            }
            int x=queries[Q[i].second][0];
            int y=queries[Q[i].second][1];
            int px=find_parent(parent,x), py=find_parent(parent,y);
            if(px==py){
                ans[Q[i].second]=true;
            }
        }
        return ans;
    }
};