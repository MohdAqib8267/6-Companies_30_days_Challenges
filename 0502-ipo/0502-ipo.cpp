class Solution {
public:
    //idea
// First we will store all the projects in projects vector as pairs {Profit(i), Capital(i)};
// Now we will sort all the projects according to its capital value.
// Now we will fetch all the projects that we can perform for our own capital value.
// After fetching all these projects sotre their profit value in Max Heap (maxProfit in below code).
// Now check if the Heap is Empty or not, if its not empty then take the top value of the heap (indicates that we chose max profit value from given projects, think greedy here).
// Now perform step 3, k times because we want to perform exactly k projects to gain max profit.
    
    //w=3, k==4
    //after sorting
    //[{4,1},{3,2},{6,4},{5,5},{4,9},{23,13},{22,15},{40,39},{49,41}]
    //ans=58  (DRY RUN)
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({profits[i],capital[i]});
        }
        //sort according to capital
        sort(v.begin(),v.end(),[&](pair<int,int>& a,pair<int,int>& b){
            return a.second<b.second;
        });
            priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        int i=0;
        while(k--){
            while(i<profits.size() and w>=v[i].second){
                pq.push(v[i]);
                i++;
            }
            if(!pq.empty()){
                w=w+pq.top().first;
                pq.pop();  
            }
          
        }
        return w;
    }
};