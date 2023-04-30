class Solution {
public:
   int ans=0;

    int find(int x,vector<int> &dsu)
    {
        if(x==dsu[x])
        {
            return x;
        }
        return dsu[x]= find(dsu[x],dsu);
    }

    void merge(int x,int y,vector<int> &dsu,vector<int> &size)
    {
        int fx=find(x,dsu);
        int fy = find(y,dsu);

        if(fx==fy)
        {
            ans++;
        }
        else
        {
            if(size[fx]>size[fy])
            {
                size[fx]+=size[fy];
                dsu[fy]=fx;
            }
            else if(size[fx]<size[fy])
            {
                size[fy]+=size[fx];
                dsu[fx]=fy;
            }
            else
            {
                size[fx]+=1;
                dsu[fy]=fx;
            }
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        vector<int> dsu;
        vector<int> size;

        //to match 1-indexed array 
        dsu.push_back(0);
        size.push_back(0);

        for(int i=1;i<=n;i++)
        {
            dsu.push_back(i);
            size.push_back(1);
        }

        for(auto it:edges)
        {
            if(it[0]==3)
            {
                merge(it[1],it[2],dsu,size);
            }
        }

        vector<int> bob=dsu;
        vector<int> alice=dsu;

        vector<int> bobs=size;
        vector<int> alices=size;

        for(auto it:edges)
        {
            if(it[0]==1)
            {
                merge(it[1],it[2],alice,alices);
            }
        }

        for(auto it:edges)
        {
            if(it[0]==2)
            {
                merge(it[1],it[2],bob,bobs);
            }
        }

        int temp=find(1,bob);
        
        for(int i=2;i<bob.size();i++)
        {
           if(temp!=find(i,bob))
           {
               return -1;
           }
        }     
        temp=find(1,alice);
        cout<<temp<<endl;
        for(int i=2;i<alice.size();i++)
        {
            cout<<find(i,alice)<<endl;
            if(temp!=find(i,alice))
            {
                return -1;
            }
        }

        return ans;       
    
    }
};