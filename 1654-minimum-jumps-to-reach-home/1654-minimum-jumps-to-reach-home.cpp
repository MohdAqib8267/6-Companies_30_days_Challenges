class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int, pair<int, bool>>> q; // {node, isBackward}
        q.push({0, {0, true}});

        set<int> s{forbidden.begin(), forbidden.end()};
        vector<int> vis(6000,0);
        vis[0] = 1;

        int ans = 0;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int steps = p.first, val = p.second.first, back = p.second.second;

            if(val == x) return steps;

            if(!back) {
                int next_pos = val - b;
                if(next_pos >= 0 and !vis[next_pos] and !s.count(next_pos)) {
                    q.push({steps + 1, {next_pos, true}});
                    vis[next_pos] = 1;
                }
            }

            int next_pos = val + a;
            if(next_pos < 6000 and !vis[next_pos] and !s.count(next_pos)) {
                q.push({steps + 1, {next_pos, false}});
                vis[next_pos] = 1;
            }
        }
        
        return -1;
    }
};