class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        int n=p.size();
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<n;i++){
           int dist = p[i][0]*p[i][0]+p[i][1]*p[i][1];
            pq.push({-1*dist,i});
        }
        vector<vector<int>> ans;
        while(k--)
        {
            auto x = pq.top();
            pq.pop();
            ans.push_back(p[x.second]);
        }
        return ans;
    }
};