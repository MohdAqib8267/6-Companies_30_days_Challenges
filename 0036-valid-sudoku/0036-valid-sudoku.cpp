class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        unordered_map<int,set<char>>row,col;
         map<pair<int,int>,set<char>>grid;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                if(num=='.'){
                    continue;
                }
                //check row
                if(row.find(i)!=row.end()){
                    //find in perticular rpw
                    if(row[i].count(num)==1){
                        return false;
                    }
                    else{
                        row[i].insert(num);
                    }
                }else{
                    row[i].insert(num);
                }
                //check col
                if(col.find(j)!=col.end()){
                    //find in perticular rpw
                    if(col[j].count(num)==1){
                        return false;
                    }
                    else{
                        col[j].insert(num);
                    }
                }else{
                    col[j].insert(num);
                }
                //check in grid
                if(grid.find({i/3,j/3})!=grid.end()){
                    if(grid[{i/3,j/3}].count(num)==1){
                        return false;
                    }else{
                        grid[{i/3,j/3}].insert(num);
                    }
                }else{
                    grid[{i/3,j/3}].insert(num);
                }
            }
        }
        return true;
    }
};