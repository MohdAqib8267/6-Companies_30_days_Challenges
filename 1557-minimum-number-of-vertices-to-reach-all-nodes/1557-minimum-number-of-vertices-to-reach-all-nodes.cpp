class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, visited(n);
        for(auto it : edges) 
            visited[it[1]] = 1;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};