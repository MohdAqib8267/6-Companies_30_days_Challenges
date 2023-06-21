class Solution {
public:
     #define ll long long
    long long minCost(vector<int>& nums, vector<int>& cost) {
       
        int n=nums.size();
         vector<pair<ll,ll>>v;
        for(ll i=0;i<n;i++)
        {
           v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i].second;
        }
        ll median=(sum+1)/2;
        ll target=0;
        ll temp=0;
        for(int i=0;i<n;i++){
            temp=temp+v[i].second;
            if(temp>=median){
                target=v[i].first;
                break;
            }
        }
        ll minCost=0;
        for(int i=0;i<n;i++){
            minCost = minCost+abs(v[i].first-target)*v[i].second;
        }
        return minCost;
    }
};