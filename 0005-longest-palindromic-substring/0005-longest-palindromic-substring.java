class Solution {
    class Result {
    int st;
    int size;

    Result(int st, int size) {
        this.st = st;
        this.size = size;
    }
}
    public int helper(int i,int j,Result result,String s,int[][] dp){
        if(i>j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s.charAt(i) == s.charAt(j)){
            dp[i][j] = helper(i+1,j-1,result,s,dp);
        }
        else{
            dp[i][j]=0;
        }
        if(dp[i][j]==1){
            if (result.size < j - i + 1)
                {
                    result.size = j - i + 1;
                    result.st = i;
                }
        }
        return dp[i][j];
    }
    public String longestPalindrome(String s) {
        int n=s.length();
        int st=-1;
        int size=0;
        if(n==1) return s;
        // for(int i=0;i<n;i++){
        //     int lo=i-1;
        //     int hi=i+1;
        //     while(lo>=0 && s.charAt(lo)==s.charAt(i)){
        //         lo--;
        //     }
        //     while(hi<n && s.charAt(hi)==s.charAt(i)){
        //         hi++;
        //     }
        //     while(lo>=0 && hi<n && s.charAt(lo)==s.charAt(hi)){
        //         lo--;
        //         hi++;
        //     }
        //     if(hi-lo-1 > size){
        //         st=lo+1;
        //         size=hi-lo-1;
        //     }
        // }
        // // System.out.println(st+" "+size);
        // return s.substring(st,st+size); //starting index,ending index(exclusive)
        int[][] dp = new int[n][n];
        Result result = new Result(0, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                helper(i,j,result,s,dp);
            }
        }
        return s.substring(result.st,result.st+result.size);
    }
}