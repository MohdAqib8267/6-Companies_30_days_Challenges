class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x==y){
                continue;
            }
            else{
                pq.push(y-x);
            }
        }
        return pq.empty()?0:pq.top();
    }
};