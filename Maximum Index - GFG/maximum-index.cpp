//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    // [34,8,8,3,2,2,2,2,1]
    // [80,80,80,80,80,33,33,1]
    
    int maxIndexDiff(int A[], int n) 
    { 
        // Your code here
vector<int>mn(n,0);
     vector<int>mx(n,0);
      
     mn[0]=A[0];
     for(int i=1; i<n; i++){
         mn[i]=min(mn[i-1],A[i]);
     }
     mx[n-1]=A[n-1];  
     for(int i=n-2; i>=0; i--){
         mx[i]=max(mx[i+1],A[i]);
     } 
     
     int i=0;
     int j=0;
     int ans =-1;
     while(i<n&&j<n){
         
         if(mx[j]>=mn[i]){
             ans=max(ans,j-i);
             j++;
         }else{
             i++;
         }
         
     }
     return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends