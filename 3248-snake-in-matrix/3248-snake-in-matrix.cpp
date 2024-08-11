class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int cnt=0;
        vector<vector<int>>grid(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=cnt++;
            }
        }
        int r=0,c=0;
        for(int i=0;i<commands.size();i++){
            string str = commands[i];
            if(str=="LEFT"){
                c=c-1;
            }
            else if(str=="DOWN"){
                r=r+1;
            }
            else if(str=="RIGHT"){
                c=c+1;
            }
            else{
                r=r-1;
            }
        }
        return grid[r][c];
    }
};