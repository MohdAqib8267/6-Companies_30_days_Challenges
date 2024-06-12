class Solution {
public:
    int solve(int i,int b,int s,vector<int>& prices){
        if(i>=prices.size()){
            return 0;
        }
        
        int buy=0,sell=0;
        if(prices[i]<prices[b]){
            buy=solve(i+1,i,s,prices);
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