class Solution {
public:
    vector<int>parent;
    vector<int>sz;
    void make_parent(int u){
        parent[u]=u;
    }
    int find_parent(int v){
        if(parent[v]==v) return v;
        
        return parent[v]=find_parent(parent[v]);
    }
    void union_set(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //DSU-->make cycle
        //if cycle exist in graph, then the edge that will participate to complete the structure of cycle, called redundent edge.
        int n=edges.size();
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            make_parent(i);
        }
        
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int x=find_parent(u);
            int y=find_parent(v);
            if(x==y){
                //form cycle
                return {u,v};
            }
            union_set(u,v);
        }
        return {};
    }
};