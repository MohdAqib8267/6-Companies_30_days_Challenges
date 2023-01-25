class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int our_score=0;
    
        for( int j=n/3;j<n;j=j+2){
            our_score+=piles[j];
        }
        return our_score;
    }
};