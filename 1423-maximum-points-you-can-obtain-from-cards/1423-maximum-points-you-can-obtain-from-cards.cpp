class Solution {
public:
    int solve(int i,int j,int k,vector<int> cardPoints){
        if(k==0){
            return 0;
        }
        if(i==j) return cardPoints[i];
        if(i>j) return 0;
        
        return max(cardPoints[i]+solve(i+1,j,k-1,cardPoints),cardPoints[j]+solve(i,j-1,k-1,cardPoints));
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        // return solve(0,n-1,k,cardPoints); 3D DP gives TLE
        
        //Approach 2
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        //now take card from end and replace first card with their position
        int i=k-1;
        int j=n-1;
        int best_comb=sum;
        for(i,j;i>=0;i--,j--){
            sum = sum - cardPoints[i] + cardPoints[j];
            best_comb = max(best_comb,sum);
        }
        return best_comb;
        
    }
};