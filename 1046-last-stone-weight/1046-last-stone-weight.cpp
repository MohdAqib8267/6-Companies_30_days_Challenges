class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int,vector<int>>q;
        for(auto i:stones){
            q.push(i);
        }
        while(q.size()>1){
            int p1=q.top();
            q.pop();
            int p2=q.top();
            q.pop();
            if(p1==p2){
                continue;
            }
            else{
                q.push(abs(p1-p2));
            }
        }
        return q.empty()?0:q.top();
    }
};