class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //1 method
	// int n=prices.size();
	// int buy[n];
	// int sell[n];
	// buy[0]=prices[0];
	// for(int i=1;i<n;i++){
	// 	buy[i]=min(buy[i-1],prices[i]);
	// }
	// sell[n-1]=prices[n-1];
	// for(int i=n-2;i>=0;i--){
	// 	sell[i]=max(sell[i+1],prices[i]);
	// }
	// int ans=0;
	// for(int i=0;i<n;i++){
	// 	ans=max(ans,sell[i]-buy[i]);
	// }
	// return ans;
    
        //2nd method
        int minVal=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            profit=max(profit,prices[i]-minVal);
            minVal=min(minVal,prices[i]);
        }
        return profit;
    }
};