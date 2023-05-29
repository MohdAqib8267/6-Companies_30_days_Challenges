class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=INT_MIN;
        vector<int>buy(n,0),sell(n,0);
        buy[0]=prices[0];
        for(int i=1;i<n;i++){
            buy[i]=min(prices[i],buy[i-1]);
        }
        sell[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            sell[i]=max(prices[i],sell[i+1]);
        }
        for(int i=0;i<n;i++){
            ans=max(sell[i]-buy[i],ans);
        }
        return ans;
    }
};