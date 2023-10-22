//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int solve(int i,int arr[],unordered_map<int,int>&mp){
        int temp=arr[i];
        int cnt=0;
        while(mp.find(temp)!=mp.end()){
            cnt++;
            temp++;
        }
        return cnt;
    }
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int>mp;
      for(int i=0;i<N;i++){
          mp[arr[i]]=i;
      }
      int mx=0;
      for(int i=0;i<N;i++){
          if(mp.find(arr[i]-1)!=mp.end()){
              continue;
          }else{
              mx=max(mx,solve(i,arr,mp));
          }
      }
      return mx;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends