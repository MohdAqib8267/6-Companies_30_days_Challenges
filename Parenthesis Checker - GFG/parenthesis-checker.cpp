//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char>st;
        
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }else{
                    return false;
                    break;
                }
            }
            else if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                    break;
                }
            }
            else if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                    break;
                }
            }
        }
        if(!st.empty()){
           return false; 
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends