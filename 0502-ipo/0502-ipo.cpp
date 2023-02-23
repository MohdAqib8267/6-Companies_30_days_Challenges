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
    
    //greedy
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       //maxheap
        priority_queue<pair<int,int>>pq;
        vector<pair<int,int>>v;
        int n=profits.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
       
        int i=0;
        while( k--){
           while(i<n and v[i].first<=w){
               pq.push({v[i].second,v[i].first});
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