class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(n,1);
        //[5, 6, 2, 2, 4, 8, 9, 5, 4, 0, 5, 1]
        //[1, 2, 1, 1, 2, 3, 4, 1, 1, 1, 2, 1] left to right
        //[ 1,2, 1, 1,  2, 3, 4, 1, 2, 1, 2, 1] right to left
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(ratings[i]<ratings[i+1]){
                candies[i+1]=1+candies[i];
            }
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                if(candies[i-1]<(candies[i]+1))
                {
                    candies[i-1]=candies[i]+1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            sum+=candies[i];
        }
        return sum;
    }
};