//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // static bool cmp(vector<int>&a, vector<int>&b){
    //     return a[1]<b[1];
    // }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         int n=intervals.size();
         sort(intervals.begin(),intervals.end());
         vector<vector<int>>ans;
        int j=0;
         int i=1;
         ans.push_back(intervals[0]);
         while(i<n){
             if(ans[j][1]>=intervals[i][0]){
                 ans[j][1]=max(ans[j][1],intervals[i][1]);
                 i++;
             }else{
                 ans.push_back(intervals[i]);
                 j++;
                 i++;
             }
             
         }
         
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends