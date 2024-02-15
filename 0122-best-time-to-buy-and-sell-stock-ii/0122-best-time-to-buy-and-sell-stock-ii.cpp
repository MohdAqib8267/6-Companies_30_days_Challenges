class Solution {
public:
    int solve(int i,int buy,int sell,vector<int>& prices,int n){
        if(i>=n){
            return 0;
        }
        int b=0,s=0;
        if( prices[i]<prices[buy]){
            //buy stock
           b=solve(i+1,i,sell,prices,n); 
        }else{
            //sell
            s=(prices[i]-prices[buy])+solve(i+1,i,i,prices,n);
        }
        return max(b,s);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(1,0,0,prices,n);
        
    }
};