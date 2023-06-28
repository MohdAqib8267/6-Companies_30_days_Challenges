class Solution {
public:
    vector<int>parent,sz;
    int find_parent(int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=find_parent(parent[v]);
    }
    void make_union(int u,int v){
        int a=find_parent(u);
        int b=find_parent(v);
        if(a==b){
            return;
        }
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int m=connections.size();
        if(n-1>m){
            return -1;
        }
        int cnt=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            int x=find_parent(u);
            int y=find_parent(v);
            if(x==y){
                cnt++;
            }
            else{
                make_union(u,v);
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                comp++;
            }
        }
        //like 3 comp and 2 node hai to connect kr payenge
        if(comp-1 > cnt){
            return -1;
        }
        return comp-1;
    }
};