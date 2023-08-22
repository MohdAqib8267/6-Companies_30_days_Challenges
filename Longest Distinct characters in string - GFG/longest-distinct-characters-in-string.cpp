//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n=s.size();
    int res=1;
    for(int i=0;i<n;i++){
        vector<bool>vis(26,false);
        int j;
        for( j=i;j<n;j++){
            if(vis[s[j]-'a']){
                break;
            }
            vis[s[j]-'a']=true;
        }
        res=max(res,j-i);
        
    }
    return res;
}