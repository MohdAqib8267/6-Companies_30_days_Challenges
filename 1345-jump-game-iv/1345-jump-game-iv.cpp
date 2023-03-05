class Solution {
public:
    int minJumps(vector<int>& arr) {
         int n = arr.size();
        int cnt=0;
        unordered_map<int,vector<int>>mpp;
        vector<int>vis(n,0);
        vis[0]=1;
        for(int i=0;i<n;i++) mpp[arr[i]].push_back(i);
        queue<int>q;
        q.push(0);
        if(arr[0]==arr[n-1] and n>1){
            return 1;
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int t = q.front(); q.pop();
                 vis[t]=1;
                if(t==n-1) return cnt;
                vector<int>temp = mpp[arr[t]];
                if(t-1>=0) temp.push_back(t-1);
                if(t+1<n) temp.push_back(t+1);
                for(auto it:temp){
                    if(!vis[it]){
                        q.push(it);
                       
                    }
                }
                mpp[arr[t]].clear();
            }
            cnt++;
        }
        return 0;
    }
};