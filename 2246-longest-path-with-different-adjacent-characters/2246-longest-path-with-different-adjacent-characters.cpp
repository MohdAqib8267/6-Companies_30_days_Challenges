class Solution {
public:    
//     Intuition
// Classic dfs problem on the tree.


// Explanation
// dfs(i) return the the longest path starting at the node i.

// dfs on each node i, and for each node i,
// we iterate on all its children,
// and find all the path startint at the node i.
// The 2 longest path can make up the longest path in subtree of node i,
// we update the global result res,
// and return the longest path length as result for dfs.
     int longestPath(vector<int>& parent, string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> children(n, vector<int>());
        for (int i = 1; i < n; ++i)
            children[parent[i]].push_back(i);
        dfs(children, s, res, 0);
        return res;
    }

    int dfs(vector<vector<int>>& children, string& s, int& res, int i) {
        int big1 = 0, big2 = 0;
        for (int& j : children[i]) {
            int cur = dfs(children, s, res, j);
            if (s[i] == s[j]) continue;
            if (cur > big2) big2 = cur;
            if (big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }


};