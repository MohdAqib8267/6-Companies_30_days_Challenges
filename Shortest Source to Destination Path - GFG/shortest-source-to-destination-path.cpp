//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    if (A[0][0] != 1 || A[X][Y] != 1) {
        return -1; // Check if the starting or ending cell is not reachable.
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    vector<vector<int>> dist(N, vector<int>(M, 0));

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};

    q.push({0, 0});
    vis[0][0] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == X && c == Y) {
            return dist[r][c];
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && A[nr][nc] == 1 && !vis[nr][nc]) {
                q.push({nr, nc});
                vis[nr][nc] = true;
                dist[nr][nc] = dist[r][c] + 1;
            }
        }
    }

    return -1; // If the target cell is not reachable.
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends