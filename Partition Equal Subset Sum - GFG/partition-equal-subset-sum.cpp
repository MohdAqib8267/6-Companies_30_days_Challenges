//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int i,int k,int arr[]){
    if(i<0){
        if(k==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(k==0){
        return 1;
    }
    if(k<0) return 0;
    return solve(i-1,k-arr[i],arr) || solve(i-1,k,arr);
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        int k=sum/2;
        return solve(N-1,k,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends