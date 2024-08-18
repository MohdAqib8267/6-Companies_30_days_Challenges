class Solution {
public:
    //typeOfDrink==0?take drink from A : take drink from B
    int solve(vector<int>&A,vector<int>&B,int hour,int typeOfDrink,vector<vector<long long>>&dp){
        if(hour>=A.size()){
            return 0;
        }
        if(dp[hour][typeOfDrink] != -1) return dp[hour][typeOfDrink];
        long long takeDrink = typeOfDrink==0?A[hour]:B[hour];
        
        long long notSwitchtoanother = takeDrink+solve(A,B,hour+1,typeOfDrink,dp);
        long long switchtoanother = takeDrink+solve(A,B,hour+2,1-typeOfDrink,dp);
        
        return dp[hour][typeOfDrink] = max(notSwitchtoanother,switchtoanother);
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        // vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        //if we start from array A
        // long long startA = solve(energyDrinkA,energyDrinkB,0,0,dp);//0->hour(index) 0->track of array(type of drink)
        //if start from array B
        // long long startB = solve(energyDrinkA,energyDrinkB,0,1,dp);

        // return max(startA,startB);
        
        //Tabulation
       vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

    // Base case: when we have only one size array, take the maximum energy drink value
    dp[1][0] = energyDrinkA[0];
    dp[1][1] = energyDrinkB[0];

    // Fill the DP table
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {  
            long long takeDrink = j == 0 ? energyDrinkA[i - 1] : energyDrinkB[i - 1];
            
            long long notSwitchtoanother = takeDrink + dp[i - 1][j];
            long long switchtoanother = takeDrink;
            if (i > 1) {  // Ensure i-2 is within bounds
                switchtoanother += dp[i - 2][1 - j];
            }

            dp[i][j] = max(notSwitchtoanother, switchtoanother);
        }
    }
    
    // Return the maximum of the last options (whether ending with A or B)
    return max(dp[n][0], dp[n][1]);
    }
};