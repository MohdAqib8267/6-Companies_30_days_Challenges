//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &grid,int n,string &temp,vector<string>&ans){
        if(i==n-1 and j==n-1){
            ans.push_back(temp);
            return;
        }
        grid[i][j]=2;
        //Down
        if(i+1<n and grid[i+1][j]==1){
            temp.push_back('D');
            solve(i+1,j,grid,n,temp,ans);
            temp.pop_back();
        }
        //left
         if(j-1>=0 and grid[i][j-1]==1){
            temp.push_back('L');
            solve(i,j-1,grid,n,temp,ans);
            temp.pop_back();
        }
        //up
          if(i-1>=0 and grid[i-1][j]==1){
            temp.push_back('U');
            solve(i-1,j,grid,n,temp,ans);
            temp.pop_back();
        }
        //Right
         if(j+1<n and grid[i][j+1]==1){
            temp.push_back('R');
            solve(i,j+1,grid,n,temp,ans);
            temp.pop_back();
        }
        grid[i][j]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        string temp="";
        if(m[0][0]==0){
            return ans;
        }
        solve(0,0,m,n,temp,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends