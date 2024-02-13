class Solution {
public:
    void solve(vector<vector<int>>& image,int i,int j,int &col,int m,int n){
       
        int curr=image[i][j];
        image[i][j]=col;
        if(i-1>=0 and image[i-1][j]==curr){
            solve(image,i-1,j,col,m,n);
        }
        if(j-1>=0 and image[i][j-1]==curr){
            solve(image,i,j-1,col,m,n);
        }
        if(i+1<m and image[i+1][j]==curr){
            solve(image,i+1,j,col,m,n);
        }
        if(j+1<n and image[i][j+1]==curr){
            solve(image,i,j+1,col,m,n);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]!=color){
              solve(image,sr,sc,color,m,n);
        }
      
        return image;
    }
};