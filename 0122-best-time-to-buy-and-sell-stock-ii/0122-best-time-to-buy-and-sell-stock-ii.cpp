class Solution {
public:
    int solve(int i,int s,int b,vector<int>&prices){
        if(i>=prices.size()){
            return 0;
        }
        int buy=0,sell=0;
        if(prices[b]>prices[i]){
            buy=solve(i+1,s,i,prices);
        }
        else{
            sell = (prices[i]-prices[b])+solve(i+1,i,i,prices);
        }
        return max(buy,sell);
    }
    int maxProfit(vector<int>& prices) {
        return solve(1,0,0,prices);
    }
};