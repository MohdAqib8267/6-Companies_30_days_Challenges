class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>dist;
        vector<int>ans(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            int currDist = abs(queries[i][0])+abs(queries[i][1]);
            dist.push(currDist);
            if(dist.size()>k){
                dist.pop();
            }
            if(dist.size()==k){
                ans[i]=dist.top();
            }
        }
        return ans;
    }
};