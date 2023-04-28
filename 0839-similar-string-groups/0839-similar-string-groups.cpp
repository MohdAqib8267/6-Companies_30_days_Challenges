class Solution {
public:
    vector<int>parent;
    vector<int>size;
    
    bool isSimilar(string s1,string s2){
        int cnt=0;
        //if cnt==0 its means both strings are similar, and if cnt==2 then it's meanst that we need only 1 swap and other cases string never similar for this problems
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                cnt++;
            }
        }
        return cnt==0 || cnt==2 ? true:false;
    }
    int find_set(int v){
        if(parent[v]==v) return v;
        
        return parent[v]=find_set(parent[v]);
    }
    
    void union_set(int a,int b){
        a=find_set(a);
        b=find_set(b);
        
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b]=a;
            size[a]=size[a]+size[b];
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    union_set(i,j);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(i==parent[i]){
                res++;
            }
        }
        return res;
    }
};