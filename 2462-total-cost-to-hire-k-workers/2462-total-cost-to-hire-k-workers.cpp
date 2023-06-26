class Solution {
public:
    
    long long totalCost(vector<int>& costs, int k, int candidates) {
         priority_queue<long long,vector<long long>,greater<long long>>pq1,pq2;
        int count=0;
        long long i=0,j=costs.size()-1;
        long long cost=0;
        while(count<k){
            while(pq1.size()<candidates and i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<candidates and j>=i){
                pq2.push(costs[j--]);
            }
            int a=pq1.size()>0?pq1.top():INT_MAX;
            int b=pq2.size()>0?pq2.top():INT_MAX;
            if(a<=b){
                cost=cost+a;
                pq1.pop();
            }
            else{
                cost=cost+b;
                pq2.pop();
            }
            count++;
        }
        return cost;
    }
};