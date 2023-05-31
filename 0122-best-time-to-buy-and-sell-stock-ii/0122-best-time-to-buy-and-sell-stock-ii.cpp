class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        int last=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>last){
                profit+=prices[i]-last;
            }
            last=prices[i];
        }
        return profit;
    }
};