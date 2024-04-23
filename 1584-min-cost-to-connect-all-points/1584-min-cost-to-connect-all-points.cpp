class Solution {
public:
    struct node{
        int u;
        int v;
        int w;
        node(int a,int b,int c){
            u=a;
            v=b;
            w=c;
        }
    };
    static bool cmp(node* a,node* b){
        return a->w < b->w;
    }
    vector<int>parent;
    vector<int>sz;
    void make_set(int v){
        parent[v]=v;
        sz[v]=1;
    }
    int find_set(int v){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=find_set(parent[v]);
    }
    void union_set(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(a != b){
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            parent[b]=a;
            sz[a]+=sz[b];
            
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        //kruskal algorithm for minimum cost
        //but theese points converted into graph
        int n=points.size();
        vector<node*>edges;
        parent=vector<int>(n);
        sz=vector<int>(n);
        for(int i=0;i<n;i++){
            make_set(i);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xi=abs(points[i][0]-points[j][0]);
                int yi=abs(points[i][1]-points[j][1]);
                node* n=new node(i,j,xi+yi);
                edges.push_back(n);
            }
        }
        int cost=0;
        sort(edges.begin(),edges.end(),cmp);//according to small weights
        for(auto e:edges){
            int u=e->u;
            int v=e->v;
            int w=e->w;
            int x=find_set(u);
            int y=find_set(v);
            if(x==y){
                continue;
            }
            else{
                cost+=w;
                union_set(u,v);
                
            }
        }
        return cost;
    }
};