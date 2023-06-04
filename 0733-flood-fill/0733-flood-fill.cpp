class Solution {
public:
    void solve(int i,int j,int oldCol,int newCol,vector<vector<int>>& image){
        if(i<0 or i>=image.size() or j<0 or j>=image[0].size()){
            return;
        }
        if(image[i][j]!=oldCol){
            return;
        }
        image[i][j]=newCol;
        solve(i,j-1,oldCol,newCol,image);
        solve(i-1,j,oldCol,newCol,image);
        solve(i,j+1,oldCol,newCol,image);
        solve(i+1,j,oldCol,newCol,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldCol=image[sr][sc];
        int newCol=color;
        if(image[sr][sc]!=newCol){
             solve(sr,sc,oldCol,newCol,image);
        }
        return image;
    }
};