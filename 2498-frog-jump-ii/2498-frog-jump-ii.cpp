class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        if(n==2) return stones[1]-stones[0];
        int prev=0;
        int d=INT_MIN;
        int st=(n%2==0)?1:2;
        for(int x=st; x<n; x+=2)
        {
            int diff=stones[x]-stones[prev];
            d=max(d,diff);
            prev=x;
        }
        for(int x=n-2; x>=0; x-=2)
        {
            int diff=stones[prev]-stones[x];
            d=max(d,diff);
            prev=x;
        }
        return d;
    }
};