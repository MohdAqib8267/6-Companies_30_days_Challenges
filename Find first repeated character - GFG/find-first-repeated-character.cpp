//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    unordered_map<char,int>mp;
    string ans="";
    for(int i=0;i<s.size();i++){
        if(mp[s[i]]==0){
            mp[s[i]]++;
        }else{
            ans.push_back(s[i]);
            break;
        }
    }
    if(ans.size()==0){
        return "-1";
    }return ans;
}