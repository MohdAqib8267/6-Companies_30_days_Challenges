class Solution {
public:
    long long MOD = 1000000007;
    int t[1001][1001];
    int solve(int targetidx,int colidx,vector<vector<int>>&freq,string &target)
    {
        //if we have founded complete target string, return 1
        if(targetidx==target.size())
        return 1;
        //this condition will be encountered when it will not be possible to form valid string
        if(colidx==freq.size())
        return 0;
        //answer is previously calculated
        if(t[targetidx][colidx]!=-1)
        return t[targetidx][colidx];
        char ch=target[targetidx];
        int notpick=solve(targetidx,colidx+1,freq,target);
        int pick=0;
        if(freq[colidx][ch-'a']!=0)
        {
            pick=(freq[colidx][ch-'a']*(long long)solve(targetidx+1,colidx+1,freq,target))%MOD;
        }
        return t[targetidx][colidx]=(pick+notpick)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        int m=words.size(),n=words[0].size();
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0;i<=target.size();i++)
        {
            for(int j=0;j<=n;j++)
            {
                t[i][j]=-1;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                freq[j][(words[i][j]-'a')]++;
            }
        }
        int ans=solve(0,0,freq,target);   
        return ans; 
}
};