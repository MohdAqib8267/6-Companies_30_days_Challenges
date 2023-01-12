class Solution {
public:
      unordered_map<char, int> dfs(int node, vector<int> adj[], string &l, vector<int> &ans, vector<int> &vis) {
        unordered_map<char, int> m;
        vis[node] = 1;
        for(int ad : adj[node]) {
            if(vis[ad]) continue;
            unordered_map<char, int> temp = dfs(ad, adj, l, ans, vis);
            for(auto i : temp) m[i.first] += i.second;
        }
        ans[node] = ++m[l[node]];
        return m;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
          vector<int> adj[n];
        for(auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        vector<int> ans(n), vis(n);
      
        dfs(0,adj,labels,ans,vis);
        return ans;
    }
};