//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int nums[], int n)
    { 
        //Your code here
        sort(nums,nums+n);
        for(int i=0;i<n;i++){
            int lo=i+1,hi=n-1;
            while(lo<hi){
                if(nums[i]+nums[lo]+nums[hi]==0){
                    return true;
                }else if(nums[i]+nums[lo]+nums[hi]<0){
                    lo++;
                }else{
                    hi--;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends