class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minVal=prices[0];
        int profit=INT_MIN;
        for(int i=0;i<n;i++){
            minVal = min(minVal,prices[i]);
            profit = max(profit,prices[i]-minVal);
        }
        return profit;
    }
};