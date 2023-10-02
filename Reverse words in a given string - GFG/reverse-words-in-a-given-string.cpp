//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        int n=s.size();
        string ans;
        int i=0,j=n-1;
        string temp="";
        while(i<=j){
            if(s[i]=='.'){
                if(ans.size()==0){
                    ans=ans+temp;
                    temp="";
                }
                else{
                    ans=temp+'.'+ans;
                    temp="";
                }
            }else{
                temp.push_back(s[i]);
                
            }
            i++;
        }
        if(temp.size()==n){
            ans=temp;
        }else{
           ans=temp+'.'+ans; 
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends