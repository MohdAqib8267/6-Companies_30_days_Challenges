class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //for validate rows and cols
        map<int,set<char>>mp_row, mp_col;
        //for validate 3*3 matrices
        map<pair<int,int>,set<char>>grid;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                if(num=='.'){
                    continue;
                }
                //check for rows
                if(mp_row.find(i)!=mp_row.end()){
                    //check this num repeat or not
                    if(mp_row[i].count(num)==1){
                        return false;
                    }
                    else{
                        mp_row[i].insert(num);
                    }
                }else{
                    mp_row[i].insert(num);
                }
                //check for cols
                if(mp_col.find(j)!=mp_col.end()){
                    //check this col present or not
                    if(mp_col[j].count(num)==1){
                        return false;
                    }else{
                        mp_col[j].insert(num);
                    }
                }else{
                    mp_col[j].insert(num);
                }
                //check for a perticular 3*3 grid
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