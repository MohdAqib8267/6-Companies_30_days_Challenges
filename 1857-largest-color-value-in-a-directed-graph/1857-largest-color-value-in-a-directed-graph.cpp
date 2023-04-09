class Solution {
public:
  vector<list<int>> graph;
    vector<vector<int>> countMap;
    vector<bool> stack;
    const char* Colors;
    bool cycle;

    void DFS(int u)
    {
        if(stack[u])
            cycle = true;
        if(cycle)
            return;
        stack[u] = true;

        vector<int> arr(26, 0);

        for(auto const& v : graph[u])
        {
            if(countMap[v].size() == 0)
                DFS(v);

            if(cycle)
                return;

            for(int i = 0; i < 26; i++)
                arr[i] = max(arr[i], countMap[v][i]);
                
        }

        arr[Colors[u] - 'a']++;
        countMap[u] = arr;
        stack[u] = false;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        graph.resize(n);
        stack = vector<bool>(n, false);
        countMap.resize(n);
        cycle = false;
        Colors = colors.c_str();
        for(auto const& edge : edges)
            graph[edge[0]].push_back(edge[1]);

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(countMap[i].size() == 0)
            {
                DFS(i);
                if(cycle)
                    return -1;
                for(int j = 0; j < 26; j++)
                    ans = max(ans, countMap[i][j]);
            }
        }

        return ans;
    }
};