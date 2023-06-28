class Solution {
public:
    vector<int>parent;
    int find_par(int v){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=find_par(parent[v]);
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]== '='){
                int x=find_par(equations[i][0]-'a');
                 int y=find_par(equations[i][3]-'a');
                if(x == y){
                    continue;
                }
                parent[y]=x;
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]== '!'){
                int x=find_par(equations[i][0]-'a');
                 int y=find_par(equations[i][3]-'a');
                if(x==y){
                    return false;
                }
            }
        }
        return true;
    }
};