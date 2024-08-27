class Solution {
public:

bool helper(int i, int j, string &s, vector<vector < int>> &dp, int &maxlen, int &start)
        {
            if (i > j) return true;
            if (dp[i][j] != -1) return dp[i][j];
            if (s[i] == s[j])
            {
                dp[i][j] = helper(i + 1, j - 1, s, dp, maxlen, start);
            }
            else
            {
                dp[i][j] = false;
            }
            if (dp[i][j] == 1)
            {
                if (maxlen < j - i + 1)
                {
                    maxlen = j - i + 1;
                    start = i;
                }
            }
            return dp[i][j];
        }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        // int size=0;
        // int st=-1;
        // for(int i=0;i<n;i++){
        //     int lo=i-1, hi=i+1;
        //     while(lo>=0 && s[lo]==s[i]){
        //         lo--;
        //     }
        //     while(hi<n && s[i]==s[hi]){
        //         hi++;
        //     }
        //     while(lo>=0 && hi<n && s[lo]==s[hi]){
        //         lo--;
        //         hi++;
        //     }
        //     if(hi-lo-1 > size){
        //         st=lo+1;
        //         size = hi-lo-1;
        //     }
        // }
        // return s.substr(st,size);
      
         
                
            int start = 0, maxlen = 1;
			
            vector<vector < int>> dp(n, vector<int> (n, -1));
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    helper(i, j, s, dp, maxlen, start);
                }
            }
            return s.substr(start, maxlen);
    }
};