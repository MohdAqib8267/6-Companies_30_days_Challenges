class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost=0;
        priority_queue<long long,vector<long long>,greater<long long>>pq1,pq2;
        int count=0;
        int i=0, j=costs.size()-1;
        while(count<k){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j--]);
            }
            long long a=pq1.size()>0?pq1.top():INT_MAX;
            long long b=pq2.size()>0?pq2.top():INT_MAX;
            if(a<=b){
                cost+=a;
                pq1.pop();
            }else{
                cost+=b;
                pq2.pop();
            }
            count++;
        }
        return cost;
    }
};